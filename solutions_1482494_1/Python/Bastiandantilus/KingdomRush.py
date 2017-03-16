from __future__ import division
import sys


if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())

    for _t in range(t):
        N = int(f.readline())
        levels = [[int(x) for x in f.readline().strip().split()] for _n in range(N)]
        goal = N * 2
        for t in range(N):
          levels[t][0] = [1, levels[t][0]]
          levels[t][1] = [2, levels[t][1]]

        stars = 0
        levels_fought = 0
        score = "Too Bad"
        reachable = True

        while N > 0 and reachable == True:
            "consider your options"
            reachable = False
            for t in sorted(list(range(N)), key = lambda level : levels[level][0][1]):
               #print t, N
               if stars >= levels[t][1][1] and levels[t][1][0] == 2 and levels[t][0][0] == 1:
                  stars += 2
                  N -= 1
                  levels.pop(t)
                  reachable = True
                  break
            if reachable == False:
              for t in sorted(list(range(N)), key = lambda level : -levels[level][1][1]):
                 if reachable == False and stars >= levels[t][1][1] and levels[t][1][0] == 2 and levels[t][0][0] == 0:
                    N -= 1
                    stars += 1
                    levels.pop(t)
                    reachable = True
                    break
              for t in sorted(list(range(N)), key = lambda level : -levels[level][1][1]):
                 if reachable == False and stars >= levels[t][0][1] and levels[t][1][0] == 2 and levels[t][0][0] == 1:
                    stars += 1
                    levels[t][0][0] = 0
                    reachable = True
                    break
            if reachable == True:
                 levels_fought += 1
            #print stars, levels
            #print

        if N == 0:
             score = levels_fought
        print ("Case #" + str(_t+1) + ": " + str(score))


