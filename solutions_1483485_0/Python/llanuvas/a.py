
sample = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
"""

hint = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
"""

m = {"q":"z", "z":"q"}
for c,h in zip(sample,hint):
    m[c] = h

#for c, h in sorted(m.iteritems()):
#  print c, "=", h


import sys

def main():
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  (t,) = get_next_int(in_file)

  results = []

  for step in xrange(0, t):
    text = get_next(in_file)
    answer = "".join([m[c] for c in text])
    results.append(answer)
    
  print_out(results, out_file)

def get_next_int(f):
  line = f.readline()
  line_data = line.rstrip('\n')
  return [int(line_data)]
  
def get_next(f):
  line = f.readline()
  line_data = line.rstrip('\n')
  return line_data
  
def print_out(results, out_file):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d: %s" % (num, result)
    #print  "Case #%d: %s" % (num, result)

if __name__ == '__main__':
  main()
