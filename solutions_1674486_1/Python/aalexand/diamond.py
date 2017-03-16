
# Check for cycles in component dependency graph
# Author: alexei.alexandrov at intel.com

#!/bin/env python

import re
import sys
import pprint
import os.path
import zipfile
import collections

sys.setrecursionlimit(100000)

class Node:
  def __init__(self) :
    self._visited = False
    self._succ = set()

  def __repr__(self):
      return str(self._succ)

# 
# args = sys.argv[1:]
# if len(args) != 1:
#     print >>sys.stderr, "usage: %s VERSION_MAPPING_ZIP_FILE" % os.path.basename(sys.argv[0])
#     sys.exit(1)
# 
# zipPath = args[0]
# 
# if not os.path.isfile(zipPath):
#     print >>sys.stderr, "file `%s' doesn't exist" % zipPath
#     sys.exit(1)
# 
# print >>sys.stderr, "processing version mappings from file `%s'" % args[0]
# 
# nodes = collections.defaultdict(Node)
# 
# zipFile = zipfile.ZipFile(args[0], "r")
# try:
#     names = zipFile.namelist()
#     for name in names:
#         print >>sys.stderr, "loading version mapping file `%s'" % name
#         content = zipFile.read(name)
# 
#         lines = content.splitlines()
# 
#         header = lines[0]
#         m = re.search(r'^PARTS: Mapping of dependents for part alias: (.*)$', header)
#         if not m:
#             print >>sys.stderr, "WARNING: the header line is invalid, skipping the file"
#             continue
# 
#         component = getComponentName(m.group(1))
# 
#         depends = '\n'.join(lines[1:])
#         dependsList = []
#         for i in re.finditer(r"\${PARTID\('[^']+','[^']+','ALIAS'\)} expanded to Part -$\s*Alias: (.+?)$", depends, re.M):
#             dependsList.append(getComponentName(i.group(1)))
# 
#         # Sanity check for correctness of the file parsing - the number of lines
#         # in the mapping file must be either 2 if there are no dependents at all
#         # or it must be 1 line per header line plus 4 lines for each dependency
#         expectedLineCount = ((1 + 4 * len(dependsList)) if len(dependsList) > 0 else 2)
#         assert len(lines) == expectedLineCount
# 
#         for i in dependsList:
#             if i != component:
#                 # Don't add self dependency because it's obvious cycle
#                 nodes[component]._succ.add(i)
# finally:
#     zipFile.close()
# 
# print >>sys.stderr, "%d nodes found, %d dependency edges" % (len(nodes), sum([len(i._succ) for i in nodes.values()]))
# 
# if debug:
#     for i in sorted(nodes.keys()):
#         print i + ": " + ','.join(sorted(nodes[i]._succ))
#     print
# 

def sccTarjan(name, stack, index, sccList):
    """Find strongly connected components in the dependency graph"""
    node = nodes[name]
    node._index = index
    node._lowlink = index
    index += 1
    stack.append(name)
    for i in node._succ:
        succ = nodes[i]
        if succ._index is None:
            index = sccTarjan(i, stack, index, sccList)
            node._lowlink = min(node._lowlink, succ._lowlink)
        elif i in stack:
            node._lowlink = min(node._lowlink, succ._index)
    if node._lowlink == node._index:
        scc = []
        while True:
            x = stack.pop()
            scc.append(x)
            if x == name:
                break
        scc.reverse()
        sccList.append(scc)
    return index


def dfsPrint(root, name, subset, stack):
    level = len(stack)
    print ' ' * level + name
    for i in nodes[name]._succ:
        if i in subset and (i not in stack or i == root):
            stack.append(i)
            dfsPrint(root, i, subset, stack)
            stack.pop()

debug = True

def dfsHasCycles(nodes, node):
    if node._visited:
        return True
    node._visited = True
    for i in node._succ:
        if dfsHasCycles(nodes, nodes[i]):
            return True
    return False

def checkCycles(nodes):
    for (k, v) in nodes.items():
        for i in nodes.itervalues():
            i._visited = False
        if dfsHasCycles(nodes, v):
            return True
    return False

f = open(sys.argv[1], "r")
test_count = int(f.readline())
for i in range(test_count):
    class_count = int(f.readline())
    nodes = collections.defaultdict(Node)
    for j in range(class_count):
        class_data = [int(z) for z in f.readline().split()]
        succ_count = class_data[0]
        assert succ_count == len(class_data) - 1
        successors = class_data[1:]
        node = nodes[j+1]
        for k in successors:
            # print k
            node._succ.add(k)

    #pprint.pprint(nodes)

    if checkCycles(nodes):
        print "Case #%d: Yes" % (i+1)
    else:
        print "Case #%d: No" % (i+1)


#    if debug:
#        print sccList
#        print

#    hasCycles = any([len(z) > 1 for z in sccList])
#    if hasCycles:
#    else:
#        print "Case #%d: No" % (i+1)

