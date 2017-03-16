from collections import defaultdict

# library online that computes maximum matching on bipartite graphs
from hopcroftkarp import HopcroftKarp

inputs = int(raw_input())

for qqq in range(inputs):
    num_lines = int(raw_input())

    graph = {}

    for line in range(num_lines):
        inp = raw_input().split(" ")
        if inp[0] in graph:
            graph[inp[0]].add(inp[1])
        else:
            graph[inp[0]] = set([inp[0]])

    matching = len(HopcroftKarp(graph).maximum_matching().keys()) / 2

    answer = matching

        
    #hash = {}
    #hash = defaultdict(lambda: 0, hash)

    #for ch in inp:
    #    hash[ch] += 1

    #h = hash
    
    #ls = [h['Z'], h['O'] - h['W'] - h['U'] - h['Z'], h['W'], h['H'] - h['G'], h['U'], h['F'] - h['U'], h['X'], h['S'] - h['X'], h['G'], h['I'] - h['G'] - h['X'] - h['F'] + h['U']]

    #out = ""
    #for i in range(len(ls)):
    #    for j in range(ls[i]):
    #        out = out + str(i)
        
    print "Case #" + str(qqq+1) + ": " + str(answer)
    
    
