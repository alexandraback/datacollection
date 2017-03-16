import os
import subprocess
import sys
import time
total = 8000
chunkSize = 320
def split(fName):
  f = open(fName)
  lines = f.readlines()
  for i in range(0, total/chunkSize):
    fi = open(str(i)+"_in.in", "w")
    fi.write(lines[0])
    l = lines[1].split(' ')
    l1 = str(chunkSize) + " "
    for ln in l[1:]:
      l1 += ln + " "
    fi.write(l1+"\n") 
    for j in range(0, chunkSize):
      fi.write(lines[2+i*chunkSize+j])
    fi.flush()
    fi.close()
    subprocess.call("./c < %s > %s &"%(str(i)+"_in.in", str(i)+"_out.out"), shell=True)
  time.sleep(100)

def merge():
  fo = open("c2.out", "w")
  fo.write("Case #1:\n")
  for i in range(0, total/chunkSize):
    f = open(str(i)+"_out.out")
    lines = f.readlines()
    for j in range(0, chunkSize):
      fo.write(lines[1+j])
  fo.flush()
  fo.close()

if __name__ == "__main__":
  if sys.argv[1] == "split":
    split(sys.argv[2])
  elif sys.argv[1] == "merge":
    merge()

