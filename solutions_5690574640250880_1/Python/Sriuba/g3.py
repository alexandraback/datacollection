# input
fi = open("python/input.txt", "r")
fo = open("python/output.txt", "wb")
t = int(fi.readline())

for z in range(0, t):
  line = [float(x)for x in fi.readline().split(' ')]
  R = int(line[0])
  C = int(line[1])
  M = int(line[2])
  non_mine = R*C - M
  star_row = ["*" for i in range(0, C)]
  dot_row = ["." for i in range(0, C)]
  if M == 0:
    output = ''.join(["c"] + dot_row[1:] + ["\n"] + (dot_row+["\n"])*(R-1))
  elif non_mine == 1:
    output = ''.join(["c"] + star_row[1:] + ["\n"] + (star_row+["\n"])*(R-1))
  elif R == 1:
    output = ''.join(star_row[:M] + dot_row[:non_mine-1] + ["c\n"])
  elif C == 1:
    output = ''.join(["*\n" for i in range(0,M)] + [".\n" for i in range(0,
      non_mine-1)] + ["c\n"]) 
  elif non_mine in  [2, 3, 5, 7]:
    output = "Impossible\n"
  elif min(R,C) == 2 and non_mine % 2 == 1:
    output = "Impossible\n"
  elif R == 2:
    output = ''.join(star_row[:int(M/2)] + dot_row[int(M/2)+1:] + ["c\n"] +
        star_row[:int(M/2)] + dot_row[int(M/2):] + ["\n"])
  elif C == 2:
    output = ''.join(["**\n" for i in range(0,int(M/2))] + ["..\n" for i in
      range(0, R-int(M/2)-1)] + ["c.\n"])
  elif non_mine < 2*R and non_mine % 2 == 0:
    output = ''.join(["c."] + star_row[2:] + ["\n"] + ([".."]+star_row[2:]+["\n"])*
      (int(non_mine/2)-1) + (star_row + ["\n"])*(R-int(non_mine/2)))
  elif non_mine < 2*R and non_mine % 2 == 1:
    output = ''.join(["c.."]+star_row[3:]+["\n"]+(["..."]+star_row[3:]+["\n"])*2
      +([".."] + star_row[2:]+["\n"])*(int((non_mine-9)/2)) + (star_row+["\n"]) 
      *(R-3-int((non_mine-9)/2)))
  else:
    t = non_mine % R # reminder
    k = int((non_mine - t)/R)
    if t == 0:
      output = ''.join(["c"] + dot_row[1:k] + star_row[k:]+ ["\n"] + 
          (dot_row[:k] + star_row[k:]+ ["\n"])*(R-1)) 
    elif t != 1:
      output = ''.join(["c"] + dot_row[:k]+star_row[k+1:] +["\n"] +
        (dot_row[:k+1]+star_row[k+1:] +["\n"])*(t-1) +
        (dot_row[:k]+star_row[k:]+["\n"])*(R-t))
    elif k > 2:
      output = ''.join(["c"] + dot_row[:k]+star_row[k+1:] +["\n"] +
        dot_row[:k+1]+star_row[k+1:] +["\n"] +
        (dot_row[:k]+star_row[k:]+["\n"])*(R-3) +
        dot_row[:k-1]+star_row[k-1:]+["\n"])
    else: # only possible if R >= 4 
      output = ''.join(["c.."]+star_row[3:]+["\n"]+(["..."]+star_row[3:]+["\n"])*2
          +([".."] + star_row[2:]+["\n"])*(R-4)+star_row+["\n"])
  fo.write(bytes("Case #"+str(z+1)+":\n"+output, 'UTF-8'))
fi.close()
fo.close()
