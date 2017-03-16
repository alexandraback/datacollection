
def output(f, n, dw, w):
  f.write("Case #" + str(n) + ": " + str(dw) + " " + str(w) + "\n")

def insert_position(num, arr):
  for i in range(len(arr)):
    if arr[i] > num:
      return i

  # insert at the end
  return len(arr)

def insert_position_binary_search(num, arr):
  if num < arr[0]:
    return 0

  if num > arr[-1]:
    return len(arr)

  left = 0
  right = len(arr) - 1
  mid = (right - left) / 2

  while left <= right:

    mid = (right - left) / 2 + left

    if num < arr[mid]:
      right = mid - 1
    else:
      left = mid + 1

  return mid

def play_war(c, a, b):
  score = 0

  while len(a) > 0:
    x = a.pop(0)
    ins_pos = insert_position_binary_search(x, b)

    if ins_pos == len(b):
      del b[0]
      score = score + 1
    else:
      del b[ins_pos]

  return score


def play_deceitful_war(c, a, b):
  score = 0

  while len(a) > 0:
    x = a.pop(0)

    if x < b[0]:
      b.pop()
    else:
      b.pop(0)
      score = score + 1

  return score

# ------- START -------

myfile = "D"
attempt = 0
testfile = "D-large"

fin = open(testfile + ".in", "r")
fout = open(testfile + ".out", "w")

num = int(fin.readline())

for n in range(num):
  count = int(fin.readline())
  naomi = [float(x) for x in fin.readline().split(" ")]
  ken = [float(x) for x in fin.readline().split(" ")]
  naomi.sort()
  ken.sort()

  deceitful_war = play_deceitful_war(count, list(naomi), list(ken))
  war = play_war(count, naomi, ken)
  
  output(fout, n + 1, deceitful_war, war)