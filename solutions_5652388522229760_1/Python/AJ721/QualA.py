def do_case(i, n):
  if n == 0:
    return "Case #%d: INSOMNIA" % i
  else:
    j = 1
    st = set()
    while True:
      lets = list(str(n*j))
      for lt in lets:
        st.add(int(lt))
      prob = False
      for k in xrange(0,10):
        if k not in st:
          prob = True
      if not prob:
        return "Case #%d: %d" % (i, n*j)
      j += 1
 
f = open("A-large.in").read()
lines = f.split("\n")
T = int(lines[0])
i=1
out=""
for line in lines[1:]:
  if len(line) > 0:
    out+=do_case(i, int(line))+"\n"
    i+=1
  
open("a-large.out","w").write(out)
 