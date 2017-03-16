#!/usr/bin/python

import sys

def make_trie(words):
  root = dict()
  for word in words:
    current_dict = root
    for letter in word:
      current_dict = current_dict.setdefault(letter, {})
    current_dict = current_dict.setdefault('_', '_')
  return root

def in_trie(trie, word):
  current_dict = trie
  for letter in word:
    if letter in current_dict:
      current_dict = current_dict[letter]
    else:
      return False
  else:
    if '_' in current_dict:
      return True
    else:
      return False

def len_in_trie(trie, word):
  current_dict = trie
  l = 0
  ls = 0
  for letter in word:
    if '_' in current_dict:
      ls = l
    if letter in current_dict:
      current_dict = current_dict[letter]
      l += 1
    else:
      return ls
  else:
    if '_' in current_dict:
      ls = l
    return ls

def min_changes(trie,S,c,lc,p):
  if p>=len(S):
    return c

  ops = []

  l = len_in_trie(trie,S[p:])
  # print l
  w = S[p:p+l]
  while len(w)>0:
    if in_trie(trie,w):
      # print w
      cc = min_changes(trie,S,c,lc,p+len(w))
      if cc == c:
        return cc
      if cc != -1:
        return cc
        # ops.append(cc)
    w = S[p:p+len(w)-1]

  si = max(lc+5,p)
  sii = min(len(S),si+M+1)
  for i in range(si,sii):
    origc = S[i]
    for nc in 'abcdefghijklmnopqrstuvwxyz':
      if nc == origc:
        continue
      nS = S[:i] + nc + S[i+1:]
      # print "try",nS
      
      l = len_in_trie(trie,nS[p:])
      if l > i-p:
        cc = min_changes(trie,nS,c+1,i,p)
        if cc != -1:
          return cc
          # ops.append(cc)

  if len(ops) == 0:
    return -1
  else:
    return min(ops)

f = open('garbled_email_dictionary.txt')
# f = open('garbled_email_dictionary_sub.txt')
words = f.readlines()
words = [x.strip() for x in words]
# print len(words)
f.close()

M = 0
for w in words:
  if len(w) > M:
    M = len(w)
# print M

trie = make_trie(words)
# print trie

print >> sys.stderr, "Trie created"

T = int(sys.stdin.readline())
for t in range(T):
  print >> sys.stderr, "Test: %d" % (t+1)
  S = sys.stdin.readline().strip()
  # print S

  c = min_changes(trie,S,0,-5,0)

  print "Case #%d: %d" % (t+1,c)

