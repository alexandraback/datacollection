def case():
  line = input()
  r, c, m = map(int, line.split(' '))
  ret = solve(r, c, m)
  assert verify(r, c, m, ret), line+'\n'+ret
  return ret

def verify(r, c, m, soln):
  if soln == 'Impossible': return True
  mines = 0
  cells = 0
  found = False
  for char in soln:
    if char == '*':
      mines+=1
      cells+=1
    elif char == 'c':
      found = True
      cells+=1
    elif char == '.':
      cells+= 1
  if found and not (mines == m and cells == r * c):
    return False
  arr = [list(x) for x in soln.split('\n')]
  cpos = None
  for i in range(len(arr)):
    if cpos:
      break
    for j in range(len(arr[i])):
      if arr[i][j] == 'c':
        cpos = (i, j)
        break
  arr[cpos[0]][cpos[1]] = '.'
  fill(arr, cpos[0], cpos[1])
  for row in arr:
    for cell in row:
      if cell == '.':
        return False
  return True

def fill(arr, x, y):
  if get(arr, x, y) != '.':
    return
  arr[x][y] = count(arr, x, y)
  if arr[x][y] == 0:
    for dx in range(-1, 2):
      for dy in range(-1, 2):
        fill(arr, x+dx, y+dy)

def count(arr, x, y):
  count = 0
  for dx in range(-1, 2):
    for dy in range(-1, 2):
      if get(arr, x+dx, y+dy) == '*':
        count += 1
  return count

def get(arr, x, y):
  if x >= 0 and x < len(arr) and y >= 0 and y < len(arr[x]):
      return arr[x][y]

def solve(r, c, m):
  if r == 1:
    return '*'*m+'.'*(c-m-1)+'c'
  if c == 1:
    return '*\n'*m+'.\n'*(r-m-1)+'c'
  if m == 0:
    return ('.'*c+'\n')*(r-1)+'.'*(c-1)+'c'
  area = r * c
  dif = area - m
  if dif == 1:
    return ('*'*c+'\n')*(r-1)+'*'*(c-1)+'c'
  if dif in [2, 3, 5, 7]:
    return 'Impossible'
  if r == 2 or c == 2:
    if dif % 2 == 0:
      if r == 2:
        return ('*'*(m//2)+'.'*(c-m//2)) + '\n' + '*'*(m//2)+'.'*(c-m//2-1)+'c'
      else:
        return '**\n'*(m//2)+'..\n'*(r-m//2-1)+'.c'
    else:
      return 'Impossible'
  arr = [['*' for x in range(c)] for y in range(r)]
  for i in range(2):
    for j in range(2):
      arr[i][j] = '.'
  arr[0][0] = 'c'
  assert r > 2
  assert c > 2
  dif -= 4

  if dif > 0:
    dif -= 2
    arr[2][0] = '.'
    arr[2][1] = '.'
  for x in range(2, c):
    if dif < 2: break
    arr[0][x] = '.'
    arr[1][x] = '.'
    dif -= 2
  for y in range(3, r):
    if dif < 2: break
    arr[y][0] = '.'
    arr[y][1] = '.'
    dif -= 2
  for y in range(2, r):
    if dif == 0: break
    for x in range(2, c):
      if dif == 0: break
      arr[y][x] = '.'
      dif -= 1
  return '\n'.join(map(lambda x: ''.join(x), arr))

def main():
  for c in range(1, int(input())+1):
    print('Case #'+str(c)+':\n'+case())

if __name__=='__main__': main()