t = int(raw_input())  # read a line with a single integer
result = ""

def getDigits(n):
    result = []
    if n == 0:
        return [0]
    while n > 0:
        result.append(n%10)
        n = n/10
    return result


for i in xrange(1, t + 1):
  n =  int(raw_input())
  if n == 0:
      result = result +  "Case #{}: INSOMNIA\n".format(i)
  else:
      a = set()
      new_n = n
      while len(a) < 10:
          digits_in_n = getDigits(new_n)
          [a.add(d) for d in digits_in_n]
          new_n = new_n + n
      result =  result + "Case #{}: {}\n".format(i, new_n - n)

file_name = "output.txt"
text_file = open(file_name, "w")
text_file.write(result)
