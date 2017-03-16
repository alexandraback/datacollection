import sys

def thing(C0,J0):
  C0=list(C0);J0=list(J0)
  n=len(C0);assert len(J0)==n
  l=[]
  for m in range(n):
    for s in [-1,0,1]:
      # Try to make 0,...,m-1 equal
      #             m differ by s (C-J=s)
      #             m+1,...,n-1 equal if s=0
      #                         C=max, J=min if s=-1
      #                         C=min, J=max if s=1
      C1=C0[:];J1=J0[:]
      for i in range(n):
        c=C0[i];j=J0[i]
        if i<m or s==0:
          if c=='?' and j=='?': C1[i]=J1[i]='0';continue
          if c=='?': C1[i]=J1[i];continue
          if j=='?': J1[i]=C1[i];continue
          continue
        if i==m:
          if s==-1:
            if c=='?' and j=='?': C1[i]='0';J1[i]='1';continue
            if c=='?':
              if j>'0': C1[i]=str(int(j)-1)
              else: C1[i]=j
              continue
            if j=='?':
              if c<'9': J1[i]=str(int(c)+1)
              else: J1[i]=c
              continue
            continue
          if s==1:
            if c=='?' and j=='?': C1[i]='1';J1[i]='0';continue
            if c=='?':
              if j<'9': C1[i]=str(int(j)+1)
              else: C1[i]=j
              continue
            if j=='?':
              if c>'0': J1[i]=str(int(c)-1)
              else: J1[i]=c
              continue
            continue
          assert 0
        if s==-1:
          if c=='?': C1[i]='9'
          if j=='?': J1[i]='0'
        elif s==1:
          if c=='?': C1[i]='0'
          if j=='?': J1[i]='9'
        else:
          if c=='?' and j=='?': C1[i]=J1[i]='0';continue
          if c=='?': C1[i]=J1[i];continue
          if j=='?': J1[i]=C1[i];continue
      l.append((C1,J1))
  best0=best1=best2=1e100
  for (C1,J1) in l:
    C=''.join(C1);J=''.join(J1)
    c=int(C);j=int(J)
    d=abs(c-j)
    if d<best0 or (d==best0 and c<best1) or (d==best0 and c==best1 and j<best2):
      best0=d;best1=c;best2=j;bestC=C;bestJ=J
  return bestC+' '+bestJ
  
T=int(sys.stdin.readline())
for case in range(1,T+1):
  [C,J]=sys.stdin.readline().strip().split()
  print "Case #%d:"%case,thing(C,J)
