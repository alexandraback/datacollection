import csv

def round_to_at_most_8(n):
  if n <= 8: return n
  if n > 8 and n%4 == 0: return 8
  else: return 4 + n%4

class Quarternion:
  def __init__(self,chr):
    self.value = chr
    with open("quarternions.csv") as f:
      self.mult_table = [x for x in csv.DictReader(f)]
      self.mult_table_index = {"i":0,"j":1,"k":2}
  
  def mult(self,mult_by):
    table_index = self.mult_table_index[mult_by]
    self.value = self.mult_table[table_index][self.value]
    return self

n = int(raw_input())
for testcase in range(n):
  [l,x] = [int(x) for x in raw_input().split()]
  x = round_to_at_most_8(x)
  long_string = raw_input()
  level = 0
  z = Quarternion("1")
  for _ in range(x):
    for chr in long_string:
      z.mult(chr)
      if level==0 and z.value == "i":
        level += 1
      elif level ==1 and z.value ==Quarternion("i").mult("j").value:
        level += 1
  
  if level == 2 and z.value == Quarternion("i").mult("j").mult("k").value:
    answer = "YES"
  else:
    answer = "NO"
  
  print "Case #%s: %s"%(testcase+1, answer)

