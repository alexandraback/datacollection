from sys import stdin

def each_case(R, C, M):
    imp = 'Impossible'
    mine = '*'
    empty = '.'
    Nempty = R*C - M  # > 0
    if R == 1:
      print mine*M + empty*(Nempty-1) + 'c'
    elif C == 1:
      if M:
        print '\n'.join([mine]*M)
      if Nempty-1:
        print '\n'.join([empty]*(Nempty-1))
      print 'c'
    elif M == 0:
      print '\n'.join([empty*C]*(R-1))
      print empty*(C-1) + 'c'
    elif Nempty == 1:
      print '\n'.join([mine*C]*(R-1))
      print mine*(C-1) + 'c'
    elif Nempty in (2,3,5,7):
      print imp
    elif R == 2:
      if M % 2:
        print imp
      else:
        print mine*(M/2) + empty*(Nempty/2)
        print mine*(M/2) + empty*(Nempty/2-1) + 'c'
    elif C == 2:
      if M % 2:
        print imp
      else:
        print '\n'.join([mine*2]*(M/2))
        print '\n'.join([empty*2]*(Nempty/2-1))
        print empty + 'c'
    elif 2*C+1 < Nempty:
      q, r = M//C, M%C    # M == qC + r
      if r == C-1:
        if q:
          print '\n'.join([mine*C]*q)
        print mine*(C-2) + empty*2
        print mine + empty*(C-1)
        print '\n'.join([empty*C]*(R-q-3))  # 2C+1 < RC-M == RC-qC-(C-1)   =>  3 < R-q
        print empty*(C-1) + 'c'
      else:
        if q:
          print '\n'.join([mine*C]*q)
        print mine*r + empty*(C-r)
        print '\n'.join([empty*C]*(R-q-2))  # 2C < RC-M <= RC-qC   =>  2 < R-q
        print empty*(C-1) + 'c'
    elif Nempty % 2:
      tmp = (Nempty-3)/2
      if R-3:
        print '\n'.join([mine*C]*(R-3))
      print mine*(C-3) + empty*3
      print mine*(C-tmp) + empty*tmp
      print mine*(C-tmp) + empty*(tmp-1) + 'c'
    else:
      tmp = Nempty/2
      print '\n'.join([mine*C]*(R-2))
      print mine*(C-tmp) + empty*tmp
      print mine*(C-tmp) + empty*(tmp-1) + 'c'


T = int(stdin.readline())
for t in xrange(T):
    print 'Case #{}:'.format(t+1)
    R, C, M = (int(s) for s in stdin.readline().split())
    each_case(R, C, M)
stdin.close()
