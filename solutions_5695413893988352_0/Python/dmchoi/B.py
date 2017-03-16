T = int(raw_input())

for t in range(T):

  (C, J) = raw_input().strip().split()

  c_a = ""
  j_a = ""

  less = 0
  for i in range(len(C)):
    if (less == 0):
      if (C[i] == "?" and J[i] == "?"):
        c_a += "0"
        j_a += "0"
      
      elif (J[i] == "?"):
        c_a += C[i]
        j_a += C[i]

      elif (C[i] == "?"):
        c_a += J[i]
        j_a += J[i]
      else:
        c_a += C[i]
        j_a += J[i]
        if (C[i] < J[i]):
          less = -1
        elif (C[i] > J[i]):
          less = 1
    else:
      c_a += C[i:]
      j_a += J[i:]
      if (less == -1):
        c_a = c_a.replace("?","9")
        j_a = j_a.replace("?","0")
      else:
        c_a = c_a.replace("?","0")
        j_a = j_a.replace("?","9")
      break;
    


    

  print "Case #{}: {} {}".format(t+1, c_a, j_a)

