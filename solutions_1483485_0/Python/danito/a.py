#!/usr/bin/python -tt

alphabet = 'abcdefghijklmnopqrstuvwxyz '
key    = 'yhesocvxduiglbkrztnwjpfmaq '

def main(line):
  plain = ''
  for j in range(len(line)):
    position = alphabet.index(line[j])
    plain = plain + key[position]
  return plain

if __name__ == '__main__':
  import sys
  N = int(sys.stdin.readline())
  for i in xrange(N):
    res = main(sys.stdin.readline().strip())
    print "Case #%d: %s" % (i + 1, res) 


