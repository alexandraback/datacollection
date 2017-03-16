import sys

class State:
   def __init__(self, n, nIdx, nEle, m, mIdx, mEle, nbToy):
      self.n = n
      self.nIdx = nIdx
      self.nEle = nEle
      self.m = m
      self.mIdx = mIdx
      self.mEle = mEle
      self.nbToy = nbToy

f = open("input")
T = int(f.readline())
for t in range(0, T):

   a = []
   b = []
   A = []
   B = []
   maxToy = 0

   values = f.readline().split()
   N = int(values[0])
   nbN = 0
   M = int(values[1])
   nbM = 0
   values = f.readline().split()
   for n in range(0, N):
      a.append(int(values[n * 2]))  
      nbN = nbN + a[-1]
      A.append(int(values[n * 2 + 1]))  

   values = f.readline().split()
   for m in range(0, M):
      b.append(int(values[m * 2]))  
      nbM = nbM + b[-1]
      B.append(int(values[m * 2 + 1]))  
   
   # Algo   
   l = []
   l.append(State(0, 0, 0, 0, 0, 0, 0))
   while len(l) > 0:
      st = l.pop()
      #print "New State", st.n, st.m, "TOY", st.nbToy
      #print "         ", st.nIdx, st.mIdx
      #print "         ", st.nEle, st.mEle

      # no more element
      if st.n >= nbN or st.m >= nbM:
         #print nbN, st.n, nbM, st.m
         if maxToy < st.nbToy:
            maxToy = st.nbToy
      else:
         # egal type
         if A[st.nIdx] == B[st.mIdx]:
            restea = a[st.nIdx] - st.nEle
            resteb = b[st.mIdx] - st.mEle
            # mange b
            if restea > resteb:
               mange = resteb 
               l.append(State(st.n     + mange,
                              st.nIdx,
                              st.nEle  + mange,
                              st.m     + mange,
                              st.mIdx  + 1,
                              0,
                              st.nbToy + mange))
            elif restea < resteb:
               mange = restea 
               l.append(State(st.n     + mange,
                              st.nIdx  + 1,
                              0,
                              st.m     + mange,
                              st.mIdx,
                              st.mEle  + mange,
                              st.nbToy + mange))
                              
            else:
               mange = restea 
               l.append(State(st.n     + mange,
                              st.nIdx  + 1,
                              0,
                              st.m     + mange,
                              st.mIdx  + 1,
                              0,
                              st.nbToy + mange))
            #print "Mange", mange

         # different
         else:
            #print "Throw"

            # jete A
            l.append(State(st.n     + a[st.nIdx] - st.nEle,
                           st.nIdx  + 1,
                           0,
                           st.m,
                           st.mIdx,
                           st.mEle,
                           st.nbToy))

            # jete B
            l.append(State(st.n,
                           st.nIdx,
                           st.nEle,
                           st.m     + b[st.mIdx] - st.mEle,
                           st.mIdx  + 1,
                           0,
                           st.nbToy))





   print "Case #%d: %d" % (t + 1, maxToy)
         
