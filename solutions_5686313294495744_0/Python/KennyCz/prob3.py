import sys
from sets import Set
import Queue



def answer(qr):
    words = [[],[]]

    for i in qr:
        if i[0] not in words[0]:
            words[0].append(i[0])
        if i[1] not in words[1]:
            words[1].append(i[1])
    edges = [ [ [] for i in range(len(words[0]))], [ [] for i in range(len(words[1]))]]

    for i in qr:
        lind =  words[0].index(i[0])
        rind = words[1].index(i[1])
        edges[0][lind].append(rind)
        edges[1][rind].append(lind)

    matched = [ [-1]* len(words[0]), [-1] * len(words[1])]

    success = True
    matches = 0
    while success:
        visited = [ [-1]* len(words[0]), [-1] * len(words[1])]
        success = False
        aug = [0,0]
        for i in range(len(words[0])):
            if matched[0][i] == -1 and visited [0][i] == -1:
                visited[0][i] = i
                q = Queue.Queue()
                q.put([i,0])
                while not q.empty() and not success:
                    node, side = q.get()
                    if side == 0:
                        for nb in edges[0][node]:
                            if visited[1][nb] == -1:
                                visited[1][nb] = node
                                q.put([nb,1])
                            if matched[1][nb] == -1:
                                aug = [i, nb]
                                success = True
                                break

                    else:
                        q.put([matched[1][node],0])
                if success:
                    matches += 1
                    l = visited[1][aug[1]]
                    matched[1][aug[1]] = l
                    r = matched[0][l]
                    matched[0][l] = aug[1]
                    while l != aug[0]:
                        l = visited[1][r]
                        matched[1][r] = l
                        nr = matched[0][l]
                        matched[0][l] = r
                        r = nr
                    break
    return len(qr) - (len(words[0]) + len(words[1]) - matches )







if __name__ == "__main__":

    T = int(sys.stdin.next())
    queries = []
    for i in range(T):
        quer = []
        N = int(sys.stdin.next())
        for i in range(N):
            quer.append(sys.stdin.next().rstrip().split(' '))
        queries.append(quer)
    for i,qr in enumerate(queries):
        print "".join(["Case #", str(i+1), ": ", str(answer(qr))])
