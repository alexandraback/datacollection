#include <cstdio>
#include <cstdlib>
#include <set>
#include <complex>
#include <cassert>


#define MAX_DIM 50
#define MAX_FOG 70

template<typename R>
static inline R Abs(R a) { return a<0?-a:a; }


char Room[MAX_DIM][MAX_DIM];

long gcd(long nom, long dem) {
  nom=Abs(nom); dem=Abs(dem);
  long p2;
  if(nom==0 || dem==0) return nom+dem;
  p2=1;
  while((nom&1)==0 && (dem&1)==0)
    p2+=p2, nom>>=1, dem>>=1;
  for(;;) {
    assert((nom|dem)&1);
    while((nom&1)==0) nom>>=1;
    while((dem&1)==0) dem>>=1;
    if(nom==dem) return p2*nom;
    assert((1&nom&dem)==1);
    if(nom>dem) nom-=dem; else dem-=nom;
  }
}

static inline
int signum(const int x) {
  return (x==0)?0:((x>0)?1:-1);
}


struct Ray {
  int dx, dy;
  Ray(int ddx, int ddy) : dx(ddx), dy(ddy) { normalize(); }
  void normalize() {
    long g=gcd(dx,dy);
    if(g!=0) {dx /= g, dy /= g;}
  }

};

int operator < (const Ray &a, const Ray &b)  {
    if(a.dx<b.dx) return 1;
    if(a.dx==b.dx) return a.dy<b.dy;
    return 0;
  }



static inline
int get_character() {
  int c;
  for(;;) {
    c=getchar();
    if(c=='.' || c=='X' || c=='#') return c;
    if(c>32) {
      fprintf(stderr, "Invalid input %c\n",c);
      exit(1);
    }
  }
}

unsigned get_unsigned() {
  int c=0;
  unsigned n=0;
  while(c>=0 && c<=32) c=getchar();
  for(;;) {
    if(c>='0' && c<='9') 
      n=n*10+(c-'0');
    else if(c<=32) return n;
    else {
      fprintf(stderr, "Invalid character %c (%d), during integer scan\n", c,c);
      exit(1);
    }
    c = getchar();
  }
}

typedef long double Real;
typedef std::complex<Real> Cmplx;


static inline 
bool close_enough(Real a, Real b) {
  return Abs(a-b)<1e-8;
}

static inline
bool close_enough(Cmplx a, Cmplx b) {
  return close_enough(a.real(), b.real()) &&
    close_enough(a.imag(), b.imag());
}

static inline
bool looks_integerely(Real a) {
  return close_enough(a,floorl(a+1e-7));
}

static inline
Real next_point(Real p, Real d) {
  if(d==0) return 1e100;
  if(d<0) p=-p, d=-d;
  assert(d>0);
  p = p-floorl(p);
  // make around gcc bug
  if(p<0.0) {
    assert(close_enough(p*100,0));
    p=0;
  }
  assert(p>=0);
  if(p>=1.0) {
    assert(close_enough((p-1)*100,0));
    p=0;
  }
    
  assert(p<1.0);
  Real res=1e-10;
  if(p<0.5) res= (0.5-p)/d;
  if(res<1e-9) 
    res = (1.0-p)/d;
  if(res<1e-9) 
    res = (1.5-p)/d;
  return res;
  
}

const Cmplx epsx(1e-6,0);
const Cmplx epsy(0,1e-6);

static inline
bool mirrored_cell(Cmplx r) {
  int x, y;
  x = floor(r.real());
  y = floor(r.imag());
  assert(x>=0);
  assert(y>=0);
  return Room[x][y]=='#';
}

int main() {
  unsigned number_of_cases;

  number_of_cases = get_unsigned();

  for(unsigned test_case=1;
      test_case<=number_of_cases;
      test_case++) {

    int H, W, D, sum=0;
    H=get_unsigned();
    W=get_unsigned();
    D=get_unsigned();
    
    Cmplx R0;
    
    for(int x=0; x<MAX_DIM; x++)
      for(int y=0; y<MAX_DIM; y++)
	Room[x][y]=0;

    for(int y=0; y<H; y++) {
      for(int x=0; x<W; x++) {
	Room[x][y]=get_character();
	if(Room[x][y]=='X') R0=Cmplx(x+0.5, y+0.5);
	if(0)printf("%c",Room[x][y]);
      }
      if(0)printf("\n");
    }


    std::set<Ray> known_rays;
    known_rays.insert(Ray(0,0));
    for(int DX=-D; DX<=D; DX++) 
      for(int DY=-D; DY<=D; DY++) {
	if(DX*DX+DY*DY>D*D) continue;
	if(known_rays.insert(Ray(DX,DY)).second==false) 
	  continue;
	Cmplx r=R0, v=Cmplx(DX,DY);
	Real dist=D;
	v /= abs(v);
	if(0)printf("v=(%Lg,%Lg)\n", v.real(), v.imag());
	assert(close_enough(abs(v),1.0));
	for(;;) {
	  /* Compute next edge or center */
	  Real tx, ty,t;
	  tx=next_point(r.real(), v.real());
	  ty=next_point(r.imag(), v.imag());
	  t = tx<ty ? tx : ty;
	  if(0) printf("dist=%g, tx=%g, ty=%g\n", (double)dist, (double)tx, (double)ty);
	  assert(t>0);
	  r += v*t;
	  if(0)printf("r=(%g,%g)\n", (double)r.real(), (double)r.imag());
	  dist -= t;
	  if(dist < -1e-6) break;
	  if(close_enough(r,R0)) {sum++; dist=-1;}
	  Cmplx rsample = r+v*(1e-4*t);
	  if(mirrored_cell(rsample)) {
	    bool intx=looks_integerely(r.real());
	    bool inty=looks_integerely(r.imag());
	    if(intx==0 && inty==0) {
	      assert(!"Bug, bug");
	    }
	    unsigned check = 0;
	    bool ckp;
	    ckp = mirrored_cell(r-epsx-epsy);
	    if(ckp) check += 1;
	    ckp = mirrored_cell(r-epsx+epsy);
	    if(ckp) check += 2;
	    ckp = mirrored_cell(r+epsx-epsy);
	    if(ckp) check += 4;
	    ckp = mirrored_cell(r+epsx+epsy);
	    if(ckp) check += 8;
#if 0
	      + (mirrored_cell(r-epsx-epsy) ? 0 : 1)
	      + (mirrored_cell(r-epsx+epsy) ? 0 : 2)
	      + (mirrored_cell(r+epsx-epsy) ? 0 : 4)
	      + (mirrored_cell(r+epsx+epsy) ? 0 : 8);
#endif
	    switch(check) {
	    case 0: case 1+8: case 2+4:
	      break;
	    case 1: case 2: case 4: case 8:
	      dist=-88; break;
	    case 1+2: case 4+8:
	      v = -conj(v); break;
	    case 1+4: case 2+8:
	      v = conj(v); break;
	    case 1+2+4: case 2+4+8: case 4+8+1: case 8+1+2:
	      v = -v; break;
	    }
	  }
	}
      }
    printf("Case #%d: %d\n", test_case, sum);
  }
  return 0;
}

#if 0
    


    known_rays.clear();
    if( scanf("%d %d %d\n", &H, &W, &D)!=3) {
      fprintf(stderr, "Invalid input at %d", __LINE__);
      return 1;
    }
    for(unsigned x=0; x<MAX_DIM; x++)
      for(unsigned y=0; y<MAX_DIM; y++) 
	Room[x][y]=0;
    
    for(int y=0; y<H; y++)  {
      char B[100];
      (void) scanf("%s",B);
      B[99]=0;
      for(int x=0; x<W; x++) {
	if(B[x]!='.' && B[x]!='#' && B[x]!='X') {
	  fprintf(stderr, "Invalid grid line ==%s=== --%c-- %d\n", B, B[x], W);
	  return 2;
	}
	Room[x][y]=B[x];
	if(B[x]=='X') startX=x, startY=y;
      }
    }
    DD=D*D;
    for(int DX=-D; DX<=D; DX++) {
      int DDX=DX*DX;
	if(DDX+DY*DY>DD) continue;
	/* Let's raytrace for StartX+0.5,StartY+0.5 to StartX+DX+0.5, StartY+DY+0.5 */

	if(known_rays.insert(Ray(DX,DY)).second==false) 
	  continue;

	if(DX==0 || DY==0) 
	  gcm=DX+DY;
	else gcm = DX*DY;
	gcm = abs(gcm);
		
	int sx0, sx, sy0, sy;
	sx0 = sx = (2*startX+1)*gcm;
	sy0 = sy = (2*startY+1)*gcm;

	int sxe, sye;
	sxe = (2*(startX+DX)+1)*gcm;
	sye = (2*(startY+DY)+1)*gcm;

	gcm*=2;

	int dx, dy;
	dx=DX;
	dy=DY; 
	int l2=(dx*dx+dy*dy);
	long long ddgcm=DD*gcm*gcm;

	if(0)
	  printf(">> DEBUG RAY: %d %d H=%d W=%d gcm=%d, dx=%d dy=%d\n", sx, sy, H, W, gcm, dx, dy);
	for(long long iter=0;; iter++) {
	  sx += dx;
	  sy += dy;
	  if(0)
	    printf("DEBUG RAY: %d %d H=%d W=%d gcm=%d, dx=%d dy=%d\n", sx, sy, H, W, gcm, dx, dy);
	assert( sx%gcm==0 || sy%gcm==0 || !fullp(sx,sy));
	if(sx%gcm==0 || sy%gcm==0) {
	  static const int A[4][3] = {
	    {-1,-1,1}, {-1,+1,2},
	    {+1,-1,4}, {+1,+1,8} };
	  int sum=0;
	  for(int i=0; i<4; i++) 
	    if( Room[ (sx+sx+A[i][0])/(2*gcm) ]
		[ (sy+sy+A[i][1])/(2*gcm) ] == '#' )
	      sum += A[i][2];
	  assert(sum>=0);
	  assert(sum<15);
	  if(0) printf("sum=%d, ", sum);
	  switch(sum) {
	  case 0: case 1+8: case 2+4:
	    break; // do nothing
	  case 1+4: case 2+8:
	    dy=-dy;
	    break;
	  case 1+2: case 4+8:
	    dx=-dx;
	    break;
	  case 1: case 2: case 4: case 8:
	    if(fullp(sx+dx, sy+dy))
	      ddgcm=-1;
	    break;
	  case 1+4+8: case 4+8+2: case 8+2+1: case 2+1+4:
	    dx=-dx; dy=-dy;
	    break;
	  default:
	    fprintf(stderr, "invalid sum=%d\n", sum);
	    assert(0&&"Shouldn't be here");
	  }
	  if((sx+dx)%gcm && (sy+dy)%gcm ) {
	    if(fullp(sx+dx, sy+dy)) {
	      fprintf(stderr, "BUG: sx=%d, dx=%d, sy=%d, dy=%d, sum=%d\n",
		      sx, dx, sy, dy, sum);
	      fprintf(stderr, "%c%c\n%c%c\n",
		      Room[(2*sx-1)/(2*gcm)][(2*sy-1)/(2*gcm)],
		      Room[(2*sx+1)/(2*gcm)][(2*sy-1)/(2*gcm)],
		      Room[(2*sx-1)/(2*gcm)][(2*sy+1)/(2*gcm)],
		      Room[(2*sx+1)/(2*gcm)][(2*sy+1)/(2*gcm)]);
	      exit(1);
	    }
	  }
	}
	if(iter*iter*l2>ddgcm+1) break;
	
	if(sx==sx0 && sy==sy0 ) 
	  sum++;
	}
      }
    }
    printf("Case #%d: %d\n", test_case, sum);
  }
  return 0;
}

#endif
