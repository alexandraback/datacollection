def possible(n, m, a):
  x = []
  hor = []
  for i in range(n):
    max = 0
    for j in range(m):
      if a[i][j] > max:
        max = a[i][j]
    x.append(max)
    hor.append(False)

  y = []
  vert = []
  for j in range(m):
    max = 0
    for i in range(n):
      if a[i][j] > max:
        max = a[i][j]
    y.append(max)
    vert.append(False)

  for i in range(n):
    for j in range(m):
      if a[i][j] != min(x[i], y[j]):
        return False

  return True

def get_ints(line):
  line = line.split(" ")
  return [int(item) for item in line]

with open("b.in", "rb") as file:
  tn = int(file.readline())
  for test in range(tn):
    tmp = get_ints(file.readline())
    n = tmp[0]
    m = tmp[1]
    a = []
    for i in range(n):
      a.append(get_ints(file.readline()))

    if possible(n, m, a):
      result = "YES"
    else:
      result = "NO"
    print "Case #{test}: {result}".format(test = test + 1, result = result)
