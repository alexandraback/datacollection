import sys, string

ori="abcdefghijklmnopqrstuvwxyz"
cyp="yhesocvxduiglbkrztnwjpfmaq"
tran=string.maketrans(ori,cyp)

def solve():
  s = raw_input()
  return s.translate(tran)

if __name__ == "__main__":
  t=input()
  for c in xrange(0,t):
        print "Case #{0}: {1}".format(c+1, solve())
