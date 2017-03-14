# /*
this_md5="$(md5sum < "$0" | cut -d' ' -f1)"
last_md5="$(readelf -p SOURCE_FILE_HASH "${0%.cpp}" 2>/dev/null | awk '/\[ *0\]/ { print $3 }')"
[ "$this_md5" != "$last_md5" ] && (
g++-4.7 -pipe -std=c++0x -Wall -Wextra -g -O2 -DTHIS_MD5="\"$this_md5\"" -o "${0%.cpp}" "$0" ||
exit 1 )
exec "${0%.cpp}" "$@"
exit 1
# */
#ifndef THIS_MD5
#define THIS_MD5 "not set"
#endif
char MD5[] __attribute__((section ("SOURCE_FILE_HASH"))) = THIS_MD5;

/*
 * This program depends on Boost
 * http://www.boost.org
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <boost/rational.hpp>
#include <boost/math/common_factor_rt.hpp>

using namespace std;
using namespace boost;

namespace
{
  class Mirrors
  {
  public:
    Mirrors( size_t w, size_t h )
      : m( h, vector< bool >( w, false ) )
    {}

    bool operator()( size_t x, size_t y ) const
    { return m[y][x]; }

    vector< bool >::reference operator()( size_t x, size_t y )
    { return m[y][x]; }

  private:
    vector< vector< bool > > m;
  };

  typedef rational< int > Coord;

  struct Position
  {
    Position() = default;

    Position( Coord ix, Coord iy )
      : x( ix ), y( iy )
    {}

    Coord x;
    Coord y;
  };

  struct Direction
  {
    Direction( int ivx, int ivy )
      : vx( ivx ), vy( ivy )
    {}

    struct hasher
    {
      size_t operator()( const Direction &dir ) const
      { return hash< int >()( dir.vx ) ^ ( hash< int >()( dir.vy ) << 1 ); }
    };

    struct equal
    {
      bool operator()( const Direction &lhs, const Direction &rhs ) const
      {
        return
          lhs.vx * rhs.vx >= 0 &&
          // vy * other.vy >= 0 &&
          lhs.vx * rhs.vy == lhs.vy * rhs.vx;
      }
    };

    int vx;
    int vy;
  };

  struct Square
  {
    Square() = default;

    Square( unsigned ix, unsigned iy )
      : x( ix ), y( iy )
    {}

    unsigned x;
    unsigned y;
  };

  void advance( Position &pos,
                const Direction &dir,
                const Square &sq,
                Coord &tx, Coord &ty )
  {
    unsigned nx = sq.x + ( dir.vx > 0 ? 1 : 0 );
    unsigned ny = sq.y + ( dir.vy > 0 ? 1 : 0 );
    Coord dx, dy;
    if( dir.vy == 0 || abs( nx - pos.x ) < abs( ( ny - pos.y ) * dir.vx / dir.vy ) )
      {
        dx = nx - pos.x;
        dy = dx * dir.vy / dir.vx;
      }
    else
      {
        dy = ny - pos.y;
        dx = dy * dir.vx / dir.vy;
      }
    pos.x += dx;
    pos.y += dy;
    tx += abs( dx );
    ty += abs( dy );
  }

  bool hit_me( const Position &pos,
               const Direction &dir,
               const Square &sq,
               const Position &me,
               Coord &tx, Coord &ty )
  {
    if( me.x >= sq.x     &&
        me.x <= sq.x + 1 &&
        me.y >= sq.y     &&
        me.y <= sq.y + 1 &&
        ( me.x - pos.x ) * dir.vx >= 0 &&
        ( me.y - pos.y ) * dir.vy >= 0 &&
        ( me.x - pos.x ) * dir.vy == ( me.y - pos.y ) * dir.vx )
      {
        tx += abs( me.x - pos.x );
        ty += abs( me.y - pos.y );
        return true;
      }
    else
      return false;
  }

  bool reflect( const Position &pos,
                Direction &dir,
                Square &sq,
                const Mirrors &mirrors )
  {
    unsigned x = pos.x.numerator() / pos.x.denominator();
    unsigned y = pos.y.numerator() / pos.y.denominator();

    unsigned dx = dir.vx < 0 ? -1 : 1;
    unsigned dy = dir.vy < 0 ? -1 : 1;

    if( pos.x == x && pos.y == y )
      {
        if( !mirrors( sq.x + dx, sq.y + dy ) )
          {
            sq.x += dx;
            sq.y += dy;
            return true;
          }
        else
          {
            if( mirrors( sq.x + dx, sq.y ) &&
                mirrors( sq.x, sq.y + dy ) )
              {
                dir.vx *= -1;
                dir.vy *= -1;
                return true;
              }
            else if( !mirrors( sq.x + dx, sq.y ) &&
                      mirrors( sq.x, sq.y + dy ) )
              {
                dir.vy *= -1;
                sq.x += dx;
                return true;
              }
            else if(  mirrors( sq.x + dx, sq.y ) &&
                     !mirrors( sq.x, sq.y + dy ) )
              {
                dir.vx *= -1;
                sq.y += dy;
                return true;
              }
            else
              return false;
          }
      }
    else if( pos.x == x )
      {
        if( mirrors( sq.x + dx, sq.y ) )
          dir.vx *= -1;
        else
          sq.x += dx;
        return true;
      }
    else if( pos.y == y )
      {
        if( mirrors( sq.x, sq.y + dy ) )
          dir.vy *= -1;
        else
          sq.y += dy;
        return true;
      }
    else
        throw logic_error( "bug in advance()?" );
  }
}

int main()
{
  unsigned nbCases;
  cin >> nbCases;
  for( unsigned noCase = 1 ; noCase <= nbCases ; noCase++ )
    {
      unsigned h, w, d;
      cin >> h >> w >> d;
      Mirrors mirrors( w, h );
      Square init_sq;
      Position me;

      assert( cin.get() == '\n' );
      for( unsigned y = 0 ; y < h ; y++ )
        {
          for( unsigned x = 0 ; x < w ; x++ )
            {
              char c = cin.get();
              switch( c )
                {
                case '#':
                  mirrors( x, y ) = true;
                  break;
                case '.':
                  break;
                case 'X':
                  init_sq = Square( x, y );
                  me = Position( x + Coord( 1, 2 ),
                                 y + Coord( 1, 2 ) );
                  break;
                default:
                  cerr << "Error: read '" << c << "'. '#', '.' or 'X' was expected." << endl;
                  abort();
                }
            }
          if( y < h - 1 ) assert( cin.get() == '\n' );
        }

      unsigned n = 0;
      unordered_set< Direction, Direction::hasher, Direction::equal > testedDir;
      for( int dir_x = -(signed)d ; dir_x <= (signed)d ; dir_x++ )
        for( int dir_y = -(signed)d ; dir_y <= (signed)d ; dir_y++ )
          {
            if( dir_x == 0 && dir_y == 0 ) continue;
            if( dir_x * dir_x + dir_y * dir_y > d * d ) continue;
            Position ray_pos( me );
            Square sq = init_sq;
            int gcd = math::gcd( dir_x, dir_y );
            Direction ray_dir( dir_x / gcd, dir_y / gcd );
            if( !testedDir.insert( ray_dir ).second ) continue;
            Coord tx( 0 ), ty( 0 );
            while( tx * tx + ty * ty < d * d )
              {
                advance( ray_pos, ray_dir, sq, tx, ty );
                if( hit_me( ray_pos, ray_dir, sq, me, tx, ty ) )
                  {
                    if( tx * tx + ty * ty <= d * d )
                      n++;
                    break;
                  }
                if( !reflect( ray_pos, ray_dir, sq, mirrors ) )
                  break;
                if( hit_me( ray_pos, ray_dir, sq, me, tx, ty ) )
                  {
                    if( tx * tx + ty * ty <= d * d )
                      n++;
                    break;
                  }
              }
          }

      cout << "Case #" << noCase << ": " << n << endl;
    }
  return EXIT_SUCCESS;
}
