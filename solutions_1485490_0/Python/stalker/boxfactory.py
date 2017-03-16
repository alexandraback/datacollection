#!/usr/bin/env python3

def S(A,B):
  if len(A) == 0 or len(B) == 0:
    return 0
  (n1,t1) = A[0]
  (n2,t2) = B[0]

  if n1 == 0:
    return S(A[1:],B)
  if n2 == 0:
    return S(A,B[1:])

  if t1 == t2:
    if n1 == n2:
      return n1 + S(A[1:],B[1:])
    elif n1 < n2:
      B[0] = (B[0][0] - n1,t1)
      return n1 + S(A[1:],B)
    else:
      A[0]= (A[0][0] - n2,t1)
      return n2 + S(A,B[1:])

  return max(S(A[1:],B),S(A,B[1:]))


def solve(As,Bs):
#  print(As)
#  print(Bs)

  return S(As,Bs)

if __name__ == "__main__":
    T = int(input());
    for c in range(T):
        (N,M) = [int(x) for x in input().strip().split()]
        As = [int(x) for x in input().strip().split()]
        Bs = [int(x) for x in input().strip().split()]

        assert 2*N == len(As)
        assert 2*M == len(Bs)

        As = [(As[2*x],As[2*x+1]) for x in range(N)]
        Bs = [(Bs[2*x],Bs[2*x+1]) for x in range(M)]

        R = solve(As,Bs)
        print("Case #{}: {}".format(c+1,R))