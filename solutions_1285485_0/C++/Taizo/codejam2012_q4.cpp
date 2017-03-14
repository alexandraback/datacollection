/*
 * main.cpp
 *
 *  Created on: 2011/09/24
 *      Author: taik
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

typedef long long s64;

#define debug_printf printf
//#define debug_printf

struct Mirror{
//public:
  double Normal[2]; // 法線方向
  double Start[2]; // 始点
  double End[2];  // 終点
};

static double my_abs(double a){
  return a > 0 ? a : -a;
}

static void mirrorPoint(double *target,const double *source,const double *base,bool x_axis){
  int fix = 1;
  int rev = 0;
  if (x_axis){ // X 座標は変わらない
    fix = 0;
    rev = 1;
  }
  target[fix] = source[fix];
  target[rev] = source[rev] - (source[rev] - base[rev]) * 2;

}

class MirrorWorld{
private:
  Mirror *mirrors_;
  int mirror_count_;
  double me_[2]; // Me;
  double base_[2]; // 左上点
  int parent_mirror_; // この世界を生み出した鏡.

  MirrorWorld(){}

public:
  MirrorWorld(double meX,double meY,Mirror *mirrors,int mirror_count){
    base_[0] = base_[1] = 0.0;
    me_[0] = meX;
    me_[1] = meY;

    mirrors_ = new Mirror[mirror_count];
    mirror_count_ = mirror_count;
    for(int i=0;i<mirror_count_;++i){
      for(int j=0;j<2;++j){
//        printf("mi %lf,%lf\n",mirrors[i].End[0],mirrors[i].End[1]);
        mirrors_[i].Start[j]  = mirrors[i].Start[j];
        mirrors_[i].End[j]    = mirrors[i].End[j];
        mirrors_[i].Normal[j] = mirrors[i].Normal[j];
      }

    }
  }
  void Print(){
    printf("base %lf,%lf\n",base_[0],base_[1]);
    printf("me   %lf,%lf\n",me_[0],me_[1]);
    for(int i=0;i<mirror_count_;++i){
      printf("mirror %d n(%lf,%lf),s(%lf,%lf),e(%lf,%lf),\n",
          i,
          mirrors_[i].Normal[0],mirrors_[i].Normal[1],
          mirrors_[i].Start[0],mirrors_[i].Start[1],
          mirrors_[i].End[0],mirrors_[i].End[1]);
    }

  }

  ~MirrorWorld(){
    delete[] mirrors_;
  }

  int GetMirrorCount(){
    return mirror_count_;
  }

  Mirror *GetMirror(int mirror_index){
    return &mirrors_[mirror_index];
  }

  double *GetMe(){
    return me_;
  }
  int GetParentMirror(){
    return parent_mirror_;
  }

  MirrorWorld *CreateMirrorWorld(int target_mirror_ind){
    MirrorWorld *new_world = new MirrorWorld();
    new_world->parent_mirror_ = target_mirror_ind;
    Mirror *target_mirror = &mirrors_[target_mirror_ind];

    bool x_axis = false;
    if (my_abs(target_mirror->Normal[0]) < my_abs(target_mirror->Normal[1])){ // X 座標は変わらない
      x_axis = true;
    }
    mirrorPoint(new_world->me_,me_,target_mirror->Start,x_axis);
    mirrorPoint(new_world->base_,base_,target_mirror->Start,x_axis);

    new_world->mirror_count_ = mirror_count_;
    new_world->mirrors_ = new Mirror[mirror_count_];
    for(int i=0;i<mirror_count_;++i){
      mirrorPoint(new_world->mirrors_[i].Start,mirrors_[i].Start,target_mirror->Start,x_axis);
      mirrorPoint(new_world->mirrors_[i].End,mirrors_[i].End,target_mirror->Start,x_axis);
      new_world->mirrors_[i].Normal[0] = mirrors_[i].Normal[0];
      new_world->mirrors_[i].Normal[1] = mirrors_[i].Normal[1];

      if (!x_axis){
        new_world->mirrors_[i].Normal[0] *= -1;
      }
      else{
        new_world->mirrors_[i].Normal[1] *= -1;
      }
    }
    return new_world;
  }

};

static double getDot(double *a,double *b){
  return a[0] * b[0] + a[1] * b[1];
}
static double* getSub(double *ab,double *a,double *b){
  ab[0] = a[0] - b[0];
  ab[1] = a[1] - b[1];

  return ab;
}

static double getLen(double *a){
  return sqrt(a[0] * a[0] + a[1] * a[1]);
}

static double getCross(double *a,double *b){
  return a[0] * b[1] - a[1] * b[0];
}

static bool isLinear(double *a,double *b,double *c){
  double ba[2];
  double ca[2];

  getSub(ba,b,a);
  getSub(ca,c,a);

  if ((ba[0] * ca[0] < 0) || (ba[1] * ca[1] < 0)){
    return false; // 符号違い.
  }


  if (((my_abs(ba[0]) <= DBL_EPSILON) && (my_abs(ba[1]) <= DBL_EPSILON))
    || ((my_abs(ca[0]) <= DBL_EPSILON) && (my_abs(ca[1]) <= DBL_EPSILON))){ // 同一点
    return true;
  }

  if (my_abs(getCross(ba,ca)) <= DBL_EPSILON){
    return true;
  }

  return false;

}

static bool isCrossed(double *a1,double *a2,double *b1,double *b2,bool on_point){
  double a2a1[2];
  double b1a1[2];
  double b2a1[2];
  double b2b1[2];
  double a1b1[2];
  double a2b1[2];

  getSub(a2a1,a2,a1);
  getSub(b1a1,b1,a1);
  getSub(b2a1,b2,a1);
  getSub(b2b1,b2,b1);
  getSub(a1b1,a1,b1);
  getSub(a2b1,a2,b1);

  double threshold = 0;
  if (on_point){
    threshold = DBL_EPSILON;
  }

  return ( getCross(a2a1, b1a1) * getCross(a2a1, b2a1) < threshold ) &&
         ( getCross(b2b1, a1b1) * getCross(b2b1, a2b1) < threshold );


}

static double getT(double *p,double *e,double *s){
  double xdiff = (e[0] - s[0]);
  if (my_abs(xdiff) > DBL_EPSILON){
    return (p[0] - s[0]) / xdiff;
  }
  else{
    return (p[1] - s[1]) / (e[1] - s[1]);
  }

}

static bool getCrossPoint(double *ret,double *a1,double *a2,double *b1,double *b2){
  double a2a1[2];
  double b2b1[2];
  double b1a1[2];

  getSub(a2a1,a2,a1);
  getSub(b1a1,b1,a1);
  getSub(b2b1,b2,b1);

  double crs = getCross(b2b1, a2a1);

  if (my_abs(crs) <= DBL_EPSILON){ // 平行.
//    printf("parallel\n");
    return false;
  }

  double scale = getCross(b2b1,b1a1) / crs;

  for(int i=0;i<2;++i){
    ret[i] = a1[i] + a2a1[i] * scale;
  }

  return true;
}


static double getDistancePL(double *a,double *b,double *c){
  double ba[2];
  double ca[2];
  double ab[2];
  double cb[2];

  if ( getDot(getSub(ba,b,a),getSub(ca,c,a)) < 0.0 ) return getLen(getSub(ca,c,a));
  if ( getDot(getSub(ab,a,b),getSub(cb,c,b)) < 0.0 ) return getLen(getSub(cb,c,b));
//  debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
  return my_abs(getCross(getSub(ba,b,a),getSub(ca,c,a))) / getLen(getSub(ba,b,a));
}

static double clamp(double x, double min, double max){
  if (x < min) return min;
  if (x > max) return max;
  return x;
}

static void q4(MirrorWorld **mirror_worlds,int target_mirror,
    double *base,
    double left_x,double left_y,
    double right_x,double right_y,
    double d,std::set<std::pair<double,double> > *result){
  MirrorWorld *mw = mirror_worlds[target_mirror];
  //mw->Print();
  //getchar();

//  debug_printf("target %d\n",target_mirror);

  // 点判定
  // 自分との距離を測る.
  if (target_mirror > 0){
    double tmp[2];
    if (getLen(getSub(tmp,base,mw->GetMe())) -d <= DBL_EPSILON){// 条件 1 像までの距離が d 以下
      bool pass = true;
//      debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
      for(std::set<std::pair<double,double> >::iterator itr = result->begin();
          itr != result->end();itr++){ // 条件 2 同一直線状の解はなし.
        double a[2];
        a[0] = itr->first;
        a[1] = itr->second;
        if (isLinear(base,a,mw->GetMe())){
          pass = false;
          break;
        }
      }
//      debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
      if (pass){
//        debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
        // 条件 3 生成された鏡面をすべて通り.それ以外の鏡面を通らない.
        for(int i=1;i<=target_mirror;++i){
          int ignore = -1;
          MirrorWorld *tmp_mw = mirror_worlds[i];
          if (i < target_mirror){// 次のやつは判定からはずしていい
            MirrorWorld *tmp_mw_next = mirror_worlds[i+1];
            ignore = tmp_mw_next->GetParentMirror();
          }

          for(int j=0;j<tmp_mw->GetMirrorCount();++j){
            if (j == ignore){
              continue;
            }
            Mirror *m = tmp_mw->GetMirror(j);

            if (j == tmp_mw->GetParentMirror()){
              if (!isCrossed(m->Start,m->End,mw->GetMe(),base,true)){
                pass = false;
                break;
              }
            }
            else{
              if (isCrossed(m->Start,m->End,mw->GetMe(),base,false)){
                pass = false;
                break;
              }
            }
          }
          if (!pass){
            break;
          }
        }
      }

      if (pass){ // OK.
//        debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
//        for(int i=1;i<=target_mirror;++i){
//          debug_printf("->%d",mirror_worlds[i]->GetParentMirror());
//        }
//        debug_printf("\n");

        result->insert(std::pair<double,double>(mw->GetMe()[0],mw->GetMe()[1]));
      }
//      debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);

    }

  }

//  debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
  // 鏡面生成
  for(int i=0;i<mw->GetMirrorCount();++i){
    Mirror *m = mw->GetMirror(i);
    double tmp[2];
//    debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);

    if (getDot(m->Normal,getSub(tmp,m->Start,base)) < 0.0){ // 条件 1 法線の向きが正しい
      double dist = getDistancePL(m->Start,m->End,base);
//      debug_printf("DB dist : %lf\n",dist);
      if (dist < d){// 条件 2 鏡面までの距離がd より小さい
        // 視野角の端と鏡面との交点を求める.
        double left_hit[2];
        double right_hit[2];
        double lt = 0.0;
        double rt = 1.0;
        double ls = 2.0;
        double rs = 2.0;
        if (target_mirror > 0){ // 最初は必ず 0,1
          double left[2]; left[0] = left_x;left[1] = left_y;
          double right[2]; right[0] = right_x;right[1] = right_y;

//          debug_printf("l,r %lf,%lf,%lf,%lf\n",left[0],left[1],right[0],right[1]);
          getCrossPoint(left_hit,base,left,m->Start,m->End);
          getCrossPoint(right_hit,base,right,m->Start,m->End);

//          debug_printf("lh,rh %lf,%lf,%lf,%lf\n",left_hit[0],left_hit[1],right_hit[0],right_hit[1]);

          // 媒介変数を求める.
          lt = getT(left_hit,m->End,m->Start);
          rt = getT(right_hit,m->End,m->Start);
          ls = getT(left_hit,left,base);
          rs = getT(right_hit,right,base);
//          debug_printf("lt,rt %lf,%lf\n",lt,rt);
          if (!((ls < 0 ) && (rs < 0))){


            if ( ls < 0){
              if (lt > rt){
                if (rt < 0) lt = rt;
                else lt =  0.0;
              }
              else{
                if (rt > 1.0) lt = rt;
                else lt =  1.0;
              }
              ls = 2.0;
            }
            if ( rs < 0){
              if (rt > lt){
                if (lt < 0) rt = lt;
                else rt =  0.0;
              }
              else{
                if (lt > 1.0) rt = lt;
                else rt =  1.0;
              }
              rs = 2.0;
            }
          }
        }
        if (((lt > 1.0) && (rt > 1.0)) || ((lt < 0.0) && (rt < 0.0)) || ((ls <= 1.0) && (rs <= 1.0)) || ((ls < 1.0) && (rs < 1.0))){ // 視野範囲外なので鏡面を作成しない.
//          debug_printf("rejected"
//              "lt=%lf,rt=%lf,ls=%lf,rs=%lf\n",lt,rt,ls,rs);
        }
        else{
          lt = clamp(lt,0.0,1.0);
          rt = clamp(rt,0.0,1.0);

          // 新しい交点を求める.
          for(int tmp=0;tmp<2;++tmp){
            left_hit[tmp] = m->Start[tmp] + (m->End[tmp] - m->Start[tmp]) * lt;
            right_hit[tmp] = m->Start[tmp] + (m->End[tmp] - m->Start[tmp]) * rt;
          }
//          debug_printf("next l,r %lf,%lf,%lf,%lf\n",left_hit[0],left_hit[1],right_hit[0],right_hit[1]);
          MirrorWorld *new_world = mw->CreateMirrorWorld(i);
  //        debug_printf("created mirror world %d\n",target_mirror + 1);
          mirror_worlds[target_mirror + 1] = new_world;
  //        debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
          q4(mirror_worlds,target_mirror + 1,base,
              left_hit[0],left_hit[1],
              right_hit[0],right_hit[1],
              d,result);
  //        debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
          delete new_world;
        }
      }
    }
  }
//  debug_printf("DB %s:%d\n",__FUNCTION__,__LINE__);
}

static void addNewMirror(std::vector<Mirror> *l, Mirror *m){
  int erase = -1;
  for(int i=0;i<l->size();++i){
    if ((l->at(i).Start[0] == m->Start[0]) &&
        (l->at(i).Start[1] == m->Start[1]) &&
        (l->at(i).End[0] == m->End[0]) &&
        (l->at(i).End[1] == m->End[1])){
      erase = i;
      break;
    }
    else if ((l->at(i).Start[0] == m->End[0]) &&
        (l->at(i).Start[1] == m->End[1]) &&
        (l->at(i).End[0] == m->Start[0]) &&
        (l->at(i).End[1] == m->Start[1])){
      erase = i;
      break;
    }
  }

  if (erase>=0){
    for(int i=erase;i<l->size()-1;++i){
      (*l)[i] = (*l)[i+1];
    }
    l->pop_back();
  }
  else{
    l->push_back(*m);
  }

}

static void mergeMirror(std::vector<Mirror> *mirrors){

  std::list<Mirror> result;
  std::set<int> removed;

  for(int i=0;i < mirrors->size();i++){
    if (removed.find(i) != removed.end()){
      continue;
    }
    Mirror m = (*mirrors)[i];
    for(int j=i+1;j<mirrors->size();++j){
      if (removed.find(j) != removed.end()){
        continue;
      }
      Mirror he = (*mirrors)[j];
      bool rem = false;
      if ((m.Normal[0] == he.Normal[0]) && (m.Normal[1] == he.Normal[1])){
        if ((m.End[0] == he.Start[0]) && (m.End[1] == he.Start[1])){
          m.End[0] = he.End[0];
          m.End[1] = he.End[1];
          rem = true;

        }
        else if ((m.End[0] == he.End[0]) && (m.End[1] == he.End[1])){
          m.End[0] = he.Start[0];
          m.End[1] = he.Start[1];
          rem = true;
        }
        else if ((m.Start[0] == he.End[0]) && (m.Start[1] == he.End[1])){
          m.Start[0] = he.Start[0];
          m.Start[1] = he.Start[1];
          rem = true;
        }
        else if ((m.Start[0] == he.Start[0]) && (m.Start[1] == he.Start[1])){
          m.Start[0] = he.End[0];
          m.Start[1] = he.End[1];
          rem = true;
        }
      }
      if (rem){
        removed.insert(j);
      }
    }
    result.push_back(m);
  }

  mirrors->clear();
  for(std::list<Mirror>::iterator itr=result.begin();itr!=result.end();++itr){
    mirrors->push_back(*itr);
  }
}

int main(int argc,const char *argv[]){

  if (argc < 2){
    printf("Usage : %s input\n",argv[0]);
    return 0;
  }


  FILE *file = fopen(argv[1],"r");

  char line[65536];

  const char *delim = " ";

  if(fgets(line,sizeof(line),file) == NULL){
    return 0;
  }
  int tc = atoi(line); // test case
  for(int i=0;i<tc;++i){
    printf("Case #%d: ",i+1);
    fgets(line,sizeof(line),file);
    char *cp = line;
    int h = atoi(strtok(cp,delim));
    cp = NULL;
    int w = atoi(strtok(cp,delim));
    double d = (double)atoi(strtok(cp,delim));

    int ans = 0;
    std::vector<Mirror > mirrors;
    // 最外周のミラーを作成.
    for(int j=0;j<w-2;++j){ // 上
      Mirror m;
      m.Normal[0] = 0.0;m.Normal[1] = -1.0;
      m.Start[0] = (double)j; m.Start[1] = (double)(h-2);
      m.End[0] = (double)(j+1);m.End[1] = (double)(h-2);
      mirrors.push_back(m);
    }
    for(int j=h-2;j>0;--j){ // 右
      Mirror m;
      m.Normal[0] = -1.0;m.Normal[1] = 0.0;
      m.Start[0] = (double)(w-2); m.Start[1] = (double)(j);
      m.End[0]   = (double)(w-2); m.End[1]   = (double)(j-1);
      mirrors.push_back(m);
    }
    for(int j=w-2;j>0;--j){ // 下
      Mirror m;
      m.Normal[0] = 0.0;m.Normal[1] = 1.0;
      m.Start[0] = (double)j; m.Start[1] = 0.0;
      m.End[0] = (double)(j-1);m.End[1] =  0.0;
      mirrors.push_back(m);
    }
    for(int j=0;j<h-2;++j){ // 左
      Mirror m;
      m.Normal[0] = 1.0;m.Normal[1] = 0.0;
      m.Start[0] = 0.0; m.Start[1] = (double)(j);
      m.End[0] =   0.0;m.End[1] =  (double)(j+1);
      mirrors.push_back(m);
    }

    double base[2];
    for(int j=h-1;j>=0;--j){

      fgets(line,sizeof(line),file);
      if ((j== h-1) || (j==0)){// 最外周の #
        continue;
      }
      for(int k=1;k<w-1;++k){
        if (line[k] == 'X'){
          base[0] = ((double)k)-0.5;
          base[1] = ((double)j)-0.5;
        }
        if (line[k] == '#'){
          { // 上
            Mirror m;
            m.Normal[0] = 0.0;m.Normal[1] = 1.0;
            m.Start[0] = (double)(k-1); m.Start[1] = (double)(j);
            m.End[0] = (double)(k);m.End[1] = (double)(j);
            addNewMirror(&mirrors,&m);
          }
          { // 右
            Mirror m;
            m.Normal[0] = 1.0;m.Normal[1] = 0.0;
            m.Start[0] = (double)(k); m.Start[1] = (double)(j);
            m.End[0]   = (double)(k); m.End[1]   = (double)(j-1);
            addNewMirror(&mirrors,&m);
          }
          { // 下
            Mirror m;
            m.Normal[0] = 0.0;m.Normal[1] = -1.0;
            m.Start[0] = (double)k; m.Start[1] = (double)(j-1);
            m.End[0] = (double)(k-1);m.End[1] =  (double)(j-1);
            addNewMirror(&mirrors,&m);
          }
          { // 左
            Mirror m;
            m.Normal[0] = -1.0;m.Normal[1] = 0.0;
            m.Start[0] = (double)(k-1); m.Start[1] = (double)(j-1);
            m.End[0] =   (double)(k-1); m.End[1] =   (double)(j);
            addNewMirror(&mirrors,&m);
          }

        }

      }
    }
/*
    for(int j=0;j<h;++j){
        {{0.0,-1.0},{0.0,4.0},{4.0,4.0}},
        {{-1.0,0.0},{4.0,4.0},{4.0,0.0}},
        {{0.0,1.0},{0.0,0.0},{4.0,0.0}},
        {{1.0,0.0},{0.0,4.0},{0.0,0.0}},

        {{0.0,1.0},{4.0,2.0},{5.0,2.0}},
//        {{1.0,0.0},{5.0,2.0},{5.0,1.0}},
        {{-1.0,0.0},{5.0,1.0},{4.0,1.0}},
        {{0.0,-1.0},{4.0,1.0},{4.0,2.0}},
    };
    */
    mergeMirror(&mirrors);
    Mirror *ms = (Mirror *)malloc(sizeof(Mirror)*mirrors.size());
    for(int j=0;j<mirrors.size();++j){
      ms[j] = mirrors[j];
    }
    MirrorWorld orig(base[0],base[1],ms,mirrors.size());

    free(ms);
//    orig.Print();

//    MirrorWorld *mw = orig.CreateMirrorWorld(&ms[0]);
//    mw->Print();

    MirrorWorld **mirror_worlds = (MirrorWorld **)malloc(sizeof(MirrorWorld * ) * 65535);
    mirror_worlds[0] = &orig;
    std::set<std::pair<double,double> > result;
    result.clear();
    q4(mirror_worlds,0,base,0,0,0,0,d ,&result);

    printf("%d\n",result.size());
  }

  fclose(file);



  return 0;
}


