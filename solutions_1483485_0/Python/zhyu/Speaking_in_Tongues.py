d = 'yhesocvxduiglbkrztnwjpfmaq'
base = ord('a')
T = input()
for i in xrange(1, T+1):
    s = map(lambda x: x if x == ' ' else d[ord(x)-base], raw_input())
    print 'Case #{0}: '.format(i) + ''.join(s)
