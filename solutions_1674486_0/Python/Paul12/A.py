#!/usr/bin/env python


def main(i,fin,fout):
    global hmm
    num = int(fin.readline())
    graph = {}
    for i in xrange(num):
        liz = map(int, fin.readline().strip().split())
        graph[i+1] = []
        for j in xrange(liz[0]):
            graph[i+1].append(liz[j+1])
    
    def dfs(node):
        for i in graph[node]:
            if i in visit:
                visit[i] = True
                return
            else:
                visit[i] = False
                dfs(i)

    found = False
    for node in graph:
        visit = {}
        visit[node] = 0
        dfs(node)
        for i in visit:
            if visit[i] == True:
                fout.write('Yes')
                found = True
                return

    fout.write('No')

fin = "A.txt"
fout = "out.txt"

if __name__ == '__main__':
    fin = open(fin, "r")
    fout = open(fout, "w")

    for i in xrange(int(fin.readline())):
        fout.write("Case #%d: " %(i+1))
        main(i,fin,fout)
        fout.write("\n")

    fin.close()
    fout.close()
