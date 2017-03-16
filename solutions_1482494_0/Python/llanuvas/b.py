from __future__ import division
import sys
import psyco
#psyco.full()

def main():
  global infile
  global out_file
  debug = False
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  if len(sys.argv)>=4:
    debug = True
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  t = get_next_int(in_file)

  results = []
  for step in xrange(int(t)):
    n = get_next_int(in_file)
    levels = [tuple(get_nexts_int(in_file)) for i in xrange(n)]
    answer = solve(n,levels)
    results.append(answer)
  print_out_int(results, out_file,debug)

def solve(n,levels):
    levels.sort()
    full_star = 2 * len(levels)
    answer = 0
    used = {}
    star = 0
    while star < full_star:

        min_one = 2002
        min_two = 2002
        for i, (a,b) in enumerate(levels):
            if a <= star and not (i,0) in used:
                if min_one == 2002:
                    min_one = i
                else:
                    if levels[i][1] > levels[min_one][1]:
                        min_one = i
            if b <= star and not (i,1) in used:
                if not (min_two,0) in used and (i,1) in used:
                    pass
                else:
                    min_two = i
            if min_one < 2002 and min_two < 2002:
                break
        if min_two < 2002:
            answer += 1
            if (min_two,0) in used:
                star += 1
                used[(min_two,1)] = 1
            else:
                star += 2
                used[(min_two,0)] = 1
                used[(min_two,1)] = 1

        elif min_one < 2002:
            answer += 1
            star += 1
            used[(min_one,0)] = 1
        else:
            break
    if star == full_star:
        return answer
    else:
        return "Too Bad"
def get_next(f):
  line = f.readline()
  return line.rstrip('\n')
def get_nexts(f):
  line = f.readline()
  return line.rstrip('\n').split(" ")

def get_next_int(f):
    return int(get_next(f))

def get_nexts_int(f):
    return map(int, get_nexts(f))
    
def get_nexts_digit(f):
    return map(int, list(get_next(f)))

def print_out(results, out_file, debug=False):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d:\n%s" % (num, result )
    if debug:
        print "Case #%d:\n%s" % (num, result )
def print_out_int(results, out_file,debug=False):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d: %s" % (num, result )
    if debug:
        print "Case #%d: %s" % (num, result )
    #print  "Case #%d: %s" % (num, result)

if __name__ == '__main__':
  main()
