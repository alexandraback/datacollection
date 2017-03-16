import sys

cache = {}
def main():
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  (t,) = get_next(in_file)

  results = []

  for step in xrange(0, t):
    (a,b) = get_next(in_file)
    global cache
    cache = {}
    answer = 0
    for n in xrange(a, b+1):
      count = check_recyclable(n, b)
      answer += count
    results.append(answer)
    
  print_out(results, out_file)

def check_recyclable(n, b):
    if n in cache:
        return cache[n]
    sn = str(n)
    recycle = 0
    ok = {}
    ng = {}
    for i in xrange(1,len(sn)):
        m = int("".join(sn[i:] + sn[:i]))
        if m > n and m <= b:
            ok[m] = 1
        else:
            ng[m] = 1
    ok_list = sorted(ok.keys())
    for i, m in enumerate(ok_list):
        cache[m] = len(ok_list) - i - 1
    return len(ok)
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
