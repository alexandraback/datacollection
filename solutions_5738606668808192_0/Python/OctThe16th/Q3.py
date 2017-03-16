def is_prime(n):
  if n == 2: return 2
  if n == 3: return 3
  if n%2 == 0: return 2
  if n < 9: return 0
  if n%3 == 0: return 3
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return f
    if n%(f+2) == 0: return f+2
    f +=6
  return 0

print("Case #1:")
count = 0
for i in range(32769, 65535):
    if(count < 50):
        good = True
        if(i%2 != 0):
            b = int(str(bin(i))[2:])
            c = []
            for j in range(9):
                if good:
                    c.append(is_prime(int(str(b), base = j+2)))
                    if c[j] == 0:
                        good = False
            if good:
                print(b, end = " ")
                for z in range(len(c)):
                    print(c[z], end = " ")
                count += 1
                print()


