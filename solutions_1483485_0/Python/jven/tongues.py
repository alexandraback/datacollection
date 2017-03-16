"""
Google Code Jam, Qualification Round 2012
http://code.google.com/codejam/contest/90101/dashboard#s=p1
"""

__author__ = 'Justin Venezuela (jven@mit.edu)'

from sys import stdin
import os

def get_translation_dictionary(clues):
  dic = {}
  cipher_cs = []
  plain_cs = []
  for (cipher, plain) in clues:
    for i in range(len(cipher)):
      dic[cipher[i]] = plain[i]
      cipher_cs.append(cipher[i])
      plain_cs.append(plain[i])
  cipher_c = ''
  plain_c = ''
  dic['q'] = 'z'
  dic['z'] = 'q'
  return dic

def parse_input(data):
  return [l.rstrip() for l in data[1:]]

def translate(cipher, dic):
  return ''.join([dic[c] for c in cipher]) 

def get_output(ciphers, dic):
  output = ''
  for i in range(len(ciphers)):
    output += 'Case #%d: %s\n' % (i + 1, translate(ciphers[i], dic))
  return output

def write_output(output, filename):
  if os.path.exists(filename):
    os.remove(filename)
  f = open(filename, 'a')
  f.write(output)
  f.close()

def test(dic):
  for i in range(ord('a'), ord('z') + 1):
    c = chr(i)
    print '%s: %s' % (c, dic[c] if c in dic else '???')

def main():
  clues = [
      ('ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand'),
      ('rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities'),
      ('de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up')]
  dic = get_translation_dictionary(clues)
  ciphers = parse_input(stdin.readlines())
  output = get_output(ciphers, dic)
  write_output(output, 'output.out')

if __name__ == '__main__':
  main()
