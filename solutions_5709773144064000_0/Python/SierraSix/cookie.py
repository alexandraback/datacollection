import sys
import re

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    data = map(float, r.split(f.readline())[:-1])
    cases.append({'c': data[0], 'f': data[1], 'x': data[2]})
  f.close()
  return cases
def cookie():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    storage = 0.0
    speed = 2.0
    time = 0.0
    if cases[i]['x']/speed < cases[i]['c']/speed:
      time = cases[i]['x']/speed
    else:
      while (1):
        remaining = cases[i]['x'] - storage
        if (storage >= cases[i]['c']):
          if remaining / speed > (remaining + cases[i]['c'])/(speed + cases[i]['f']):
            storage = storage - cases[i]['c']
            remaining = cases[i]['x'] - storage
            speed = speed + cases[i]['f']
          if (remaining <= cases[i]['c']):
            time = time + remaining/speed
            break
        storage = storage + cases[i]['c']
        time = time + cases[i]['c']/speed
    out = out + "%.6f\n" % time
    o.write(out);
  o.close();

def main():
  if len(sys.argv) != 2:
    print 'Usage: python cookie.py <input>'
  else:
    cookie()
if __name__ == '__main__':
  main()
