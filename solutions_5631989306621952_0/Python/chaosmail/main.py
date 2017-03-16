import fs
# filesystem wrapper from https://pypi.python.org/pypi/pyfs

def solve(input):
  word = ""
  for letter in input:
    if len(word) == 0:
      word = letter
    elif letter >= word[0]:
      word = letter + word
    else:
      word = word + letter

  return word

if __name__ == '__main__':
  IN_NAME = 'A-small-attempt0.in'
  OUT_NAME = 'output.txt'

  raw_input = fs.read(IN_NAME)
  print('====> Reading %s' % IN_NAME)

  rows = raw_input.split('\n')
  cases = int(rows[0])
  solution = ''

  for i, row in enumerate(rows):
    # Skip first row (contains number of entries)
    if i == 0: continue
    # Skip last row (contains only \n)
    if i == len(rows) - 1: continue
    solution += 'Case #%i: %s\n' % (i, str(solve(row)))

  fs.write(OUT_NAME, solution)
  print('====> Writing %s' % OUT_NAME)