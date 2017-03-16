import sys


def get_number_of_tests(fd):
  n = fd.readline()
  return int(n)


def get_c_f_x(fd):
  line = fd.readline()
  return map(float, line.strip().split())


def get_min_time(cost, produce, target):
  ''' c: cost, f: produce, x: target. '''
  time_consumed = 0.0
  cps = 2.0  # cookies per second
  while True:
    time_needed_without_buying = target / cps
    time_needed_if_buying = (cost / cps) + (target / (cps + produce))
    if time_needed_without_buying <= time_needed_if_buying:
      return time_consumed + time_needed_without_buying
    time_consumed += (cost / cps)
    cps += produce


def main(fd):
  n = get_number_of_tests(fd)
  for i in xrange(n):
    c, f, x = get_c_f_x(fd)
    print 'Case #%d: %.7f' % (i + 1, get_min_time(c, f, x))

if __name__ == '__main__':
  main(sys.stdin)
