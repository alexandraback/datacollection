def add_row(board, mines):
  empty = len(board[0]) - mines
  board += ["." * empty + "*" * mines]

def add_col(board, mines):
  for i in xrange(len(board) - 1, -1, -1):
    if mines > 0:
      board[i] += "*"
      mines -= 1
    else:
      board[i] += "."

def display(board):
  if board == "Impossible":
    print board
    return
  for row in board:
    print row

def solve(r, c, m):
  if m > r * c:
    return "Impossible"
  if r == 1 and c == 1:
    if m == 0:
      return ["c"]
    else:
      return "Impossible"
  if r == 2 and c == 2:
    if m == 0:
      return ["c.", ".."]
    elif m == 3:
      return ["c*", "**"]
    else:
      return "Impossible"
  if r > c:
    # Taller
    if m == c - 1 and m != 0:
      # Special case avoiding one space at the end
      result = solve(r - 1, c, 1)
      if result == "Impossible":
        return "Impossible"
      add_row(result, m - 1)
      return result
    elif m < c:
      result = solve(r - 1, c, 0)
      if result == "Impossible":
        return "Impossible"
      add_row(result, m)
      return result
    else:
      result = solve(r - 1, c, m - c)
      if result == "Impossible":
        return "Impossible"
      add_row(result, c)
      return result
  else:
    # Wider
    if m == r - 1 and m != 0:
      # Special case avoiding one space at the end
      result = solve(r, c - 1, 1)
      if result == "Impossible":
        return "Impossible"
      add_col(result, m - 1)
      return result
    elif m < r:
      result = solve(r, c - 1, 0)
      if result == "Impossible":
        return "Impossible"
      add_col(result, m)
      return result
    else:
      result = solve(r, c - 1, m - r)
      if result == "Impossible":
        return "Impossible"
      add_col(result, r)
      return result

def test_case(r, c, m):
  display(solve(r, c, m))

for i in range(int(raw_input())):
  print "Case #" + str(i + 1) + ":"
  values = [int(value) for value in raw_input().split(" ")]
  test_case(values[0], values[1], values[2])
