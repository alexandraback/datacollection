#!/usr/bin/python -tt

import sys

def translate(line): 
  key = {}
  key['a'] = 'y'
  key['b'] = 'h'
  key['c'] = 'e'
  key['d'] = 's'
  key['e'] = 'o'
  key['f'] = 'c'
  key['g'] = 'v'
  key['h'] = 'x'
  key['i'] = 'd'
  key['j'] = 'u'
  key['k'] = 'i'
  key['l'] = 'g'
  key['m'] = 'l'
  key['n'] = 'b'
  key['o'] = 'k'
  key['p'] = 'r'
  key['q'] = 'z'
  key['r'] = 't'
  key['s'] = 'n'
  key['t'] = 'w'
  key['u'] = 'j'
  key['v'] = 'p'
  key['w'] = 'f'
  key['x'] = 'm'
  key['y'] = 'a'
  key['z'] = 'q'
  
  out = ""
  for i in line: 
    try:
      out = out + key[i]
    except KeyError:
      out = out + i
  return out

def main():
  f = open("A-small-attempt0.in", 'rU')
  lines = f.readline()
  
  output = open('output', 'w')
  for i in range(int(lines)):
    line = f.readline()
    out = translate(line)
    output.write("Case #"+str(i+1)+': '+out)
    #print "Case #",print str(i+1), out, 
  f.close()
  output.close()
  
if __name__ == '__main__':
  main()
