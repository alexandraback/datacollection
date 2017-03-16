import sys

FROM = 'abcdefghijklmnopqrstuvwxyz'
TO   = 'yhesocvxduiglbkrztnwjpfmaq'

def translate(sentence):
  s = ''
  for c in sentence:
    s += TO[FROM.index(c)] if c != ' ' else ' '
  return s

with open(sys.argv[1]) as fin:
  with open('output', 'w') as fout:
    for i, line in enumerate(fin):
      if i > 0:
        fout.write('Case #%d: %s\n' % (i, translate(line.strip())))
