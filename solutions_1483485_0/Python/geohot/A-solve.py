import sys

mapping = {}

def readSample():
  f = open('A-template', 'r')
  lines = f.readlines()
  f.close()
  # extracting mapping
  for i in range(0, len(lines), 2):
    for j in range(0, len(lines[i]), 1):
      mapping[lines[i][j]] = lines[i+1][j]
    

def main():
  readSample()
  #print sorted(mapping)
  casecount = int(sys.stdin.readline())
  for i in range(1, casecount+1):
    a = sys.stdin.readline() 
    out = [mapping[x] for x in a]
    sys.stdout.write("Case #{0}: {1}".format(i,"".join(out)))
    i+=1


if __name__ == "__main__":
  main()
  
