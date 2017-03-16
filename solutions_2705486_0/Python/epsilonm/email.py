from collections import deque as Deque
alpha = 'abcdefghijklmnopqrstuvwxyz'
def addword(word, trie):
  if not word:
    trie['0'] = True
    return
  c = word[0]
  if c not in trie:
    trie[c] = {}
  addword(word[1:], trie[c])

f = open('dict.txt')
words = f.read().split()
words.sort()
trie = {}

for word in words:
  addword(word, trie)

def do(string):
  cache = {}
  mytrie = trie
  def f(tehtrie, index, canchange):
    if index == len(string):
      if '0' in tehtrie:
        return 0
      else:
        return len(string)
    key = (id(tehtrie), index)
    if key in cache:
      return cache[key]
    
    mini = len(string)
    for i in alpha:
      cmp = i==string[index]
      if (i in tehtrie) and ((canchange <= 0) or cmp):
        r = f(tehtrie[i], index+1, canchange-1 if cmp else 4)
        if not cmp: r += 1
        if r < mini:
          mini = r
      
      if ('0' in tehtrie and i in mytrie) and ((canchange <= 0) or cmp):
        r = f(mytrie[i], index+1, canchange-1 if cmp else 4)
        if not cmp: r += 1
        if r < mini:
          mini = r
    cache[key] = mini
    return mini

  return f(mytrie, 0, 0)

tests = int(raw_input())

for case in xrange(1, tests+1):
  string = raw_input()
  res = do(string)
  print 'Case #%d: %d' %(case,res)

