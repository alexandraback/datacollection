import sys
import bisect

class Level:
    def __init__(self, needed_stars, counterpart_stars):
        self.needed_stars = needed_stars
        self.counterpart_stars = counterpart_stars
    def __cmp__(self, other):
        if self.needed_stars < other.needed_stars:
            return -1
        if self.needed_stars > other.needed_stars:
            return 1
        return other.counterpart_stars - self.counterpart_stars
    def __str__(self):
        return "(%s, %s)" % (self.needed_stars, self.counterpart_stars)

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect.bisect_right(a, x)
    if i:
        return i - 1
    return -1
def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect.bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    N = int(f.readline())

    orphan_levels, easy_levels, hard_levels = [], [], []
    for n in range(0, N):
        (A, B) = [int(x) for x in f.readline().split()]
        bisect.insort(easy_levels, Level(A, B))
        bisect.insort(hard_levels, Level(B, A))

    # i start out with 0 stars
    stars = 0   
    attempts = 0

    while hard_levels or easy_levels or orphan_levels:
#        print
#        print [str(x) for x in orphan_levels]
#        print [str(x) for x in easy_levels]
#        print [str(x) for x in hard_levels]

 #       print stars
        
        found = False
        if hard_levels and hard_levels[0].needed_stars <= stars:
  #              print 'hard'
                stars += 2
                attempts += 1
                attempted_level = hard_levels.pop(0)
                counterpart = Level(attempted_level.counterpart_stars, attempted_level.needed_stars)
                j = index(easy_levels, counterpart)
                easy_levels.pop(j)
                found = True
        elif orphan_levels and orphan_levels[0] <= stars:
   #             print 'orphan'
                stars += 1 
                attempts += 1
                orphan_levels.pop(0)
                found = True
        elif easy_levels and easy_levels[0].needed_stars <= stars:
    #            print 'easy'
                stars += 1
                attempts += 1
                attempted_level = easy_levels.pop(0)
                counterpart = Level(attempted_level.counterpart_stars, attempted_level.needed_stars)
                j = index(hard_levels, counterpart)
                hard_levels.pop(j)
                bisect.insort(orphan_levels, attempted_level.counterpart_stars)
                found = True
        if not found:
            break
        found = True
                
    if not found:
        print "Case #%d: Too Bad" % (case + 1)
    else:
        print "Case #%d: %d" % (case + 1, attempts)
