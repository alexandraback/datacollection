import sys

def main():
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  (t,) = get_next(in_file)

  results = []

  for step in xrange(0, t):
    input = get_next(in_file)
    n, s, p = input[:3]
    points = input[3:]
    border = p + max(0,p-1) * 2
    suprise = p + + max(0,p-2) * 2
    count = len([point for point in points if border <= point])
    suprises = len([point for point in points if suprise <= point and point < border])
    results.append(count + min(suprises, s))
    
  print_out(results, out_file)
def get_next(f):
  line = f.readline()
  line_data = line.rstrip('\n').split(' ')
  return [int(value) for value in line_data]
  
def print_out(results, out_file):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d: %s" % (num, result)
    #print  "Case #%d: %s" % (num, result)

if __name__ == '__main__':
  main()
