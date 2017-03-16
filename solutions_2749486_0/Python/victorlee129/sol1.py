def BFS():

    def append(queue,visited,data):
        if data[1] in visited : return
        if destination in visited: return

        visited.append(data[1])
        queue.append(data)

    queue=[(0,(0,0),'')]
    visited=[(0,0)]

    while 1:
        depth,pos,route=queue.pop(0)

        if pos==destination:
            return route

        depth+=1
    
        if pos[0]-destination[0]<depth:
            append(queue,visited,(depth,(pos[0]+depth,pos[1]),route+'E'))
        if pos[0]-destination[0]>-depth:
            append(queue,visited,(depth,(pos[0]-depth,pos[1]),route+'W'))
        if pos[1]-destination[1]<depth:
            append(queue,visited,(depth,(pos[0],pos[1]+depth),route+'N'))
        if pos[1]-destination[1]>-depth:
            append(queue,visited,(depth,(pos[0],pos[1]-depth),route+'S'))

maxL=0

K=int(raw_input())
for i in range(K): 
    destination=tuple(map(int,raw_input().split()))

    print 'Case #{}: {}'.format(i+1,BFS())
