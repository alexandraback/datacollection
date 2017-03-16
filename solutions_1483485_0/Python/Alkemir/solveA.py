lines = open('a_small.txt', 'r').read().split('\n')

T = int(lines.pop(0))

toGooglerese = {}
toGooglerese['a'] = 'y'
toGooglerese['b'] = 'n'
toGooglerese['c'] = 'f'
toGooglerese['d'] = 'i'
toGooglerese['e'] = 'c'
toGooglerese['f'] = 'w'
toGooglerese['g'] = 'l'
toGooglerese['h'] = 'b'
toGooglerese['i'] = 'k'
toGooglerese['j'] = 'u'
toGooglerese['k'] = 'o'
toGooglerese['l'] = 'm'
toGooglerese['m'] = 'x'
toGooglerese['n'] = 's'
toGooglerese['o'] = 'e'
toGooglerese['p'] = 'v'
toGooglerese['q'] = 'z'
toGooglerese['r'] = 'p'
toGooglerese['s'] = 'd'
toGooglerese['t'] = 'r'
toGooglerese['u'] = 'j'
toGooglerese['v'] = 'g'
toGooglerese['w'] = 't'
toGooglerese['x'] = 'h'
toGooglerese['y'] = 'a'
toGooglerese['z'] = 'q'

fromGooglerese = {}

for x in 'abcdefghijklmnopqrstuvwxyz':
   fromGooglerese[toGooglerese[x]] = x

for t in range(T):

   googlerese = ''
   line = lines[t]
   for i in range(len(line)):
      char = line[i]
      if char != ' ':
         char = fromGooglerese[char]
      
      googlerese += char

   print 'Case #' + str(t+1) + ': ' + googlerese