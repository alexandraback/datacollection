from collections import Counter
import fs
# filesystem wrapper from https://pypi.python.org/pypi/pyfs

def solve(length, input):
  # Parse to set of int
  input = [list(map(int, a.split(" "))) for a in input]
  
  c = Counter([a[l] for a in input for l in range(length)]).most_common()
  output = sorted([a[0] for a in c if a[1] % 2])
  return " ".join(list(map(str, output)))

if __name__ == '__main__':
  IN_NAME = 'B-large.in'
  OUT_NAME = 'output.txt'

  raw_input = fs.read(IN_NAME)
  print('====> Reading %s' % IN_NAME)

  rows = raw_input.split('\n')
  cases = int(rows[0])
  solution = ''

  i = 1
  case = 1
  while True:
    # End the loop
    if i >= len(rows) - 1:
      break
    a = int(rows[i])
    solution += 'Case #%i: %s\n' % (case, str(solve(a, rows[i+1:i+2*a])))
    i += 2*a
    case += 1

  fs.write(OUT_NAME, solution)
  print('====> Writing %s' % OUT_NAME)