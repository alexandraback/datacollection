import math

fin = open('in2.txt','r')
fout = open('out2.txt','w')

T = int(fin.readline().strip())

def solve_seg(z,l_bd,r_bd):
  if len(z) == 0:
    return []
  max_loc = z.index(max(z))#assume I want first maxima
  #most I can spend and still hit RHS
  need = max(r_bd-R*(len(z)-max_loc-1),0)
  max_spend = E - need
  #want to put all weight here if we can
  if max_loc*R+l_bd <= E:
    #spend everything here.
    l = [0 for i in range(max_loc)]
    r = solve_seg(z[max_loc+1:],need + R,r_bd)#is this right?
    l.append(max_loc*R+l_bd-need)
    l.extend(r)
    return l
  else:
    #we have more than enough.  Spend max here and continue.
    l = solve_seg(z[0:max_loc],l_bd,E-R)
    r = solve_seg(z[(max_loc+1):],R+need,r_bd)
    l.append(E-need)
    l.extend(r)
    return l

for idx in range(T):
  E, R, N = [long(a) for a in fin.readline().strip().split(' ')]
  V = [long(a) for a in fin.readline().strip().split(' ')]
  X = solve_seg(V,E,0)
  print len(X)
  print len(V)
  ans = sum([V[i]*X[i] for i in range(len(V))])
  out = "Case #" + str(idx+1) + ": " + str(ans) + "\n"
  fout.write(out)

fin.close()
fout.close()
