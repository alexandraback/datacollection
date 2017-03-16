import itertools

def is_prime(n):
  if n == 2 or n == 3: return 0
  if n < 2 or n%2 == 0: return 2
  if n < 9: return 0
  if n%3 == 0: return 3
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return f
    if n%(f+2) == 0: return f+2
    f +=6
  return 0

def find_num(bin, base):
  mult = 1
  sumi = 0
  for d in reversed(bin):
    sumi += int(d)*mult
    mult *= base
  return sumi




fd = open("in3", "r")

lines = fd.readlines()

testcases = int(lines[0])

iteration = itertools.count()

fout = open("out3", "w")



for line_ind in xrange(1,len(lines)):
  line  = lines[line_ind]

  N = int(line.split(" ")[0])
  J = int(line.split(" ")[1])

  fout.write("Case #" + str(line_ind) + ":\n")

  format = "%014d"
  if(N == 32):
    format = "%030d"


  for num in iteration:
    number = format % (int(bin(num)[2:]),)
    number = "1" + number + "1"

    flag = True
    factors = []

    for i in range(2,11):
      curr = find_num(number, i)
      prime = is_prime(curr)
      if(prime > 0):
        factors.append(prime)
      else:
        flag = False
        break
    if(flag):
      fout.write(str(number) + " " + " ".join(map(str,factors)) + "\n")
      J -= 1
    if(J == 0):
      exit()


