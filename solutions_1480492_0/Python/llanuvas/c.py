from __future__ import division
import sys
import psyco
psyco.full()

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
    cars = []
    for i in xrange(n):
      lane,speed,pos = get_nexts(in_file)
      cars.append([lane,int(speed),int(pos)])
    cars.sort()
    cars.reverse()
    corisions = {}  
    for i in xrange(n):
        for j in xrange(i+1,n):
            if cars[i][1] != cars[j][1]:
                speed_diff = abs(cars[i][1] - cars[j][1])
                pos_diff   = abs(cars[i][2] - cars[j][2]) - 5
                corision_time = pos_diff / speed_diff
                if cars[i][1] > cars[j][1]:
                    corision_pos = cars[i][1] * corision_time + cars[i][2]
                else:
                    corision_pos = cars[j][1] * corision_time + cars[j][2]
                if (corision_pos,corision_time) in corisions:
                    corisions[(corision_pos,corision_time)] += 1
                else:
                    corisions[(corision_pos,corision_time)] = 1
    min_corision = -1
    for (corision_pos,corision_time),count in corisions.items():
        if count >= 2:
            if min_corision == -1:
                min_corision = corision_time
            else:
                min_corision = min(min_corision,corision_time)
             
    results.append(min_corision)
  print_out_int(results, out_file,debug)

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
