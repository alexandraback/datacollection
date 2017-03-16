#!/usr/bin/python

import sys

all_map={}
for i in range(3):
  line1 = sys.stdin.readline().strip()
  line2 = sys.stdin.readline().strip()
  for j in range(len(line1)):
    if ' ' != line1[j]:
      all_map[line1[j]] = line2[j]

#print all_map, len(all_map)

key=[False] * 26
value = [False] * 26
for k in all_map.keys():
  key[ord(k)-ord('a')]=True
  value[ord(all_map[k]) - ord('a')]=True
for c in range(26):
  if not key[c]:
    sys.stderr.write('missing key:%s\n'%(chr(c+ord('a'))))
  if not value[c]:
    sys.stderr.write('missing value:%s\n'%(chr(c+ord('a'))))

all_map['z'] = 'q'
all_map['q'] = 'z'
line_num = -1
for line in file(sys.argv[1]):
  out=''
  line_num += 1
  if line_num == 0:
    continue;
  for i in range(len(line)):
    if line[i] in all_map:
      out += all_map[line[i]]
    else:
      out += line[i]
  sys.stdout.write('Case #%d: %s'%(line_num, out))

