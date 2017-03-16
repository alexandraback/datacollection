import sys

translation = {
  ' ' : ' ',
  'a' : 'y',
  'b' : 'h',
  'c' : 'e',
  'd' : 's',
  'e' : 'o',
  'f' : 'c',
  'g' : 'v',
  'h' : 'x',
  'i' : 'd',
  'j' : 'u',
  'k' : 'i',
  'l' : 'g',
  'm' : 'l',
  'n' : 'b',
  'o' : 'k',
  'p' : 'r',
  'q' : 'z',
  'r' : 't',
  's' : 'n',
  't' :	'w',
  'u' : 'j',
  'v' : 'p',
  'w' : 'f',
  'x' : 'm',
  'y' : 'a',
  'z' : 'q'
}

i = 0
cases = int(raw_input())
while(i < cases):
    x = raw_input()
    result = []
    for p in range(len(x)):
        result.append(translation[x[p]])
    sys.stdout.write("Case #" + str(i+1) + ": " + ''.join(result) + '\n')
    i += 1
