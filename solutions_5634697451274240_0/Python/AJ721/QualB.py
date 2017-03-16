def do_case(case, str):
  prev = "+"
  count = 0
  for i in reversed(list(range(len(str)))):
    current = str[i]
    if current != prev:
      count+=1
      prev = current
  return "Case #%d: %d" % (case, count)

f = open("B-small-attempt0.in").read()
lines = f.split("\n")
T = int(lines[0])
i=1
out=""
for line in lines[1:]:
  if len(line.strip()) > 0:
    out+=do_case(i, line.strip())+"\n"
    i+=1
  
open("B-small.out","w").write(out)