
def main():
  testcases = int(input())
  for caseNr in range(1, testcases+1):
    n,m,k = map(int, input().split())
    #board = input() # legge una riga e crea una lista
    #board = [input() for i in range(4)] #legge 4 righe e crea una lista di liste
    #pattern = [list(map(int, input().split())) for i in range(N)] #
    print("Case #%i: %i" % (caseNr, solve(n,m,k)))

def solve(n,m,k):
  if n <= 2 or m <= 2:
    return k
  elif n == 3 or m == 3:
    return min(k,k-(k-2)/3)
  else:
    return min(k,k-(k-2)/3,k-(k-4)/2)

if __name__ == "__main__":
  main()
