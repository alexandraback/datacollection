FILENAME = "A-large"
# FILENAME = "test"
INPUT_FILE = "%s.in" % FILENAME
OUTPUT_FILE = "%s.out" % FILENAME

def get_graph(size):
    graph = list()
    for i in range(size):
        graph.append([False]*size)
    return graph

if __name__ == '__main__':
    input_file = open(INPUT_FILE, "r")
    output_file = open(OUTPUT_FILE, "w")
    
    cases = int(input_file.readline())
    for case in range(1, cases+1): # Count case from 1, 2, ..., n
        print "CASE %d" % case
        classes = int(input_file.readline())
        graph = get_graph(classes)
        for class_ in range(classes):
            raw = [int(i) for i in input_file.readline().split(" ")]
            if raw[0] == 0:
                continue
            else:
                for inheritance in raw[1:]:
                    graph[class_][inheritance-1] = True
                    
        queue = list()
        
        for col in range(classes):
            flag = True
            for row in range(classes):
                if graph[row][col]:
                    flag = False
            if flag:
                queue.append((col, col))
        
        passthrough = list()
        for i in range(classes):
            passthrough.append(list())
            
        finished = False
        while len(queue) > 0:
            current = queue.pop()
            # print "checking %s" % str(current)
            for col in range(classes):
                if graph[current[0]][col]: # there is a connection
                    # print current[0], col
                    if current[1] in passthrough[col]: # passed before
                        # print current
                        # print passthrough
                        output_file.write("Case #%d: Yes\n" % case)
                        finished = True
                        break
                    else:
                        passthrough[col].append(current[1])
                        queue.append((col, current[1]))
            if finished:
                break
            
        # passthrough = [[]] * classes
        #         finished = False
        #         for node in queue:
        #             for col in range(classes):
        #                 if graph[node][col]:
        #                     if node in passthrough[col]:
        #                         output_file.write("Case #%d: Yes\n" % case)
        #                         finished = True
        #                         break
        #                     else:
        #                         passthrough[col].append(node)
        #                 
        #     if finished:
        #         break
        
        if not finished:
            output_file.write("Case #%d: No\n" % case)
        # print graph
    
    input_file.close()
    output_file.close()
