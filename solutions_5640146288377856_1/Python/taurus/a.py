import math

def main():
  testcases = int(input())
  for caseNr in range(1, testcases+1):
    r,c,w = map(int, input().split())
    #board = input() # legge una riga e crea una lista
    #board = [input() for i in range(4)] #legge 4 righe e crea una lista di liste
    #pattern = [list(map(int, input().split())) for i in range(N)] #
    print("Case #%i: %i" % (caseNr, solve(r,c,w)))
    
def solve(r,c,w):
  return (r-1) * math.floor(c/w) + math.floor((c-1)/w) + w
      
if __name__ == "__main__":
  main()
    