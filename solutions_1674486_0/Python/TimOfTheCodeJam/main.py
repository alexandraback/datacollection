

class Node(object):
    
    def __init__(self, number):
        self.number = number
        self.children = []
    
    def __str__(self):
        return "Node %s" % self.number
    
    __repr__ = __str__
    
    def has_diamond(self, visited = None):
        visited = set() if visited is None else visited
        for node in self.children:
            if node.number in visited:
                return True
            visited.add(node.number)
            if node.has_diamond(visited):
                return True
            
        return False
            
def main():
    with open('input.txt') as f:        
        all_lines = f.readlines()
        
    num_cases = int(all_lines[0])
    result = []
    last_index = 0
    for case_nbr in xrange(num_cases):
        print "case", case_nbr
        num_classes = int(all_lines[last_index+1])
        node_dict = {}
        root_nodes = []
        for class_number in xrange(num_classes):
            class_number = class_number + 1
            parents = [int(i) for i in all_lines[last_index+1+class_number].split()]
            parents = parents[1:]
            if class_number not in node_dict:
                node_dict[class_number] = Node(class_number)
            if len(parents) == 0:
                root_nodes.append(node_dict[class_number])
                
            for parent in parents:
                if parent not in node_dict:
                    node_dict[parent] = Node(parent)
                node_dict[parent].children.append(node_dict[class_number])
                
        last_index = last_index + num_classes + 1
        
        has_diamond = False
        for root in root_nodes:
            has_diamond = root.has_diamond()
            if has_diamond:
                break
        
        answer = "Yes" if has_diamond else "No"
        result.append( "Case #%s: %s\n" % (case_nbr+1, answer))
    
    with open('output.txt','w') as f:        
        all_lines = f.writelines(result)
    
        
        
main()
print "done"    

    
