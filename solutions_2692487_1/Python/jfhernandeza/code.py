def solve(**kwargs):
  
  A = kwargs['A']
  M = kwargs['M']
  
  m = len(M)
  
  n = 0
  M.sort()
  i = 0
  
  while i < len(M) and M[i] < A:
    
    A += M[i]
    i += 1
  
  M = M[i:]
  
  while len(M) > 0:
    
    if A - 1 > 0 and len(M) > 1:
      A += A - 1
    
      i = 0
      while i < len(M) and M[i] < A:
	A += M[i]
	i += 1
    
      M = M[i:]
    
    else:
      
      M = M[:len(M) - 1]
    
    n += 1
  
  return str(min(n,m))

if __name__ == "__main__":
  
  f_in = open('file.in','r')
  f_out = open('file.out','w')

  N = int(f_in.readline())

  for i in range(N):
    problem = {}
    problem['A'] = int(f_in.readline().replace('\n','').split(' ')[0])
    problem['M'] = [int(t) for t in f_in.readline().replace('\n','').split(' ')]
  
    f_out.write('Case #' + str(i + 1) + ': ' + solve(**problem) + '\n')

  f_in.close()
  f_out.close