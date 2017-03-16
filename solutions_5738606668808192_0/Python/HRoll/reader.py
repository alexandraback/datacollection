# derpy library for reading files
# for all functions, f is a file open for read
# no error checking; assumes f.readline() will work
# removes the trailing newline

def readLineAsInt(f):
  s = f.readline().strip()
  return int(s)

def readLineAsIntArr(f, splitter=None):
  if splitter is None:
    tokens = f.readline().split()
  else:
    tokens = f.readline().strip().split(splitter)
  return list(map(int, tokens))

def readLineAsStr(f):
  s = f.readline().strip()
  return s

def readLineAsStrArr(f, splitter=None):
  if splitter is None:
    tokens = f.readline().split()
  else:
    tokens = f.readline().strip().split(splitter)
  return tokens

