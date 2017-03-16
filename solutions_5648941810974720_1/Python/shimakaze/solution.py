from collections import Counter

def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    string = f.readline().strip()
    ans = ''
    print "Doing case %d: " % (nt+1)
    c = Counter(string)
    
    num0 =  c['Z']
    c = remove_occurences(c, 'ZERO', num0)
    ans += num0 * '0'

    num2 =  c['W']
    c = remove_occurences(c, 'TWO', num2)
    ans += num2 * '2'

    num6 =  c['X']
    c = remove_occurences(c, 'SIX', num6)
    ans += num6 * '6'

    num8 =  c['G']
    c = remove_occurences(c, 'EIGHT', num8)
    ans += num8 * '8'

    num3 =  c['H']
    c = remove_occurences(c, 'THREE', num3)
    ans += num3 * '3'

    num4 =  c['R']
    c = remove_occurences(c, 'FOUR', num4)
    ans += num4 * '4'

    num5 =  c['F']
    c = remove_occurences(c, 'FIVE', num5)
    ans += num5 * '5'

    num7 =  c['V']
    c = remove_occurences(c, 'SEVEN', num7)
    ans += num7 * '7'

    num1 =  c['O']
    c = remove_occurences(c, 'ONE', num1)
    ans += num1 * '1'

    num9 =  c['N'] / 2
    c = remove_occurences(c, 'NINE', num9)
    ans += num9 * '9'

    ans = ''.join(sorted(ans))

    if sum(c.values()) != 0:
      raise Exception

    o.write("Case #%d: %s\n" % ((nt+1), ans))

def remove_occurences(c, string, num):
  temp_c = Counter(string * num)
  return c - temp_c

solve('A-large.in')
