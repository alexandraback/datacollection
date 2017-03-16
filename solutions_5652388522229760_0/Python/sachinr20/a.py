import sys

nums = []

name = sys.argv[1]

with open(name) as f:
    lines = f.readlines()

lines = lines[1:]
for inp in lines:
    nums.append(int(inp))

case = 0
with open("out.txt", "w") as o:
  for i in nums:
      case = case + 1
      print("Case #"+str(case)+": ", end="")
      o.write("Case #"+str(case)+": ")
      if i==0:
          print("INSOMNIA")
          o.write("INSOMNIA\n")
          continue
      l = set()
      [l.add(x) for x in str(i)]
      j = 0
      while len(l)!=10:
          j = j+1
          [l.add(x) for x in str(i*j)]
      print(i*j)
      o.write(str(i*j)+"\n")
      del l

