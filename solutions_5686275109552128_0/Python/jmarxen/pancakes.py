def heap_parent(i):
    return (i-1) >> 1
    
def heap_lchild(i):
    return (i << 1) + 1
    
def heap_rchild(i):
    return (i << 1) + 2

class max_heap:
    
    def __init__(self):
        self.q = []
        self.len=0
    
    def swap(self,i1,i2):
        t = self.q[i1]
        self.q[i1]=self.q[i2]
        self.q[i2]=t
        
    def bubble_up(self,index):
        if index == 0:
            return
        
        p = heap_parent(index)
        cur_v = self.q[index][1]
        p_v = self.q[p][1]
        if p_v < cur_v:
            self.swap(index,p)
            self.bubble_up(p)
        
    def trickle_down(self,index):
        
        cur_val = self.q[index][1]
        l_child = heap_lchild(index)
        r_child = l_child+1
        if l_child >= self.len:
            return
        l_val = self.q[l_child][1]
        if r_child >= self.len:
            if l_val > cur_val:
                self.swap(index,l_child)
            return
        r_val = self.q[r_child][1]
        if l_val > cur_val:
            if r_val > l_val:
                self.swap(index,r_child)
                self.trickle_down(r_child)
            else:
                self.swap(index,l_child)
                self.trickle_down(l_child)
        elif r_val > cur_val:
            self.swap(index,r_child)
            self.trickle_down(r_child)
    
    def add(self, elm, val):
        self.q.append((elm,val))
        self.bubble_up(self.len)
        self.len+=1
    
    def pop(self):
        if self.len==0:
            return None
        rv = self.q[0][0]
        leaf = self.q.pop()
        self.len-=1
        if self.len > 0:
            self.q[0]=leaf
            self.trickle_down(0)
        return rv
    
    def peek(self):
        return self.q[0][0]

    def copy(self):
        new_heap = max_heap()
        new_heap.q = [(x[0],x[1]) for x in self.q]
        new_heap.len = self.len
        
def divide_stack(stack_size, target_size):
    rv = stack_size/target_size
    if stack_size % target_size == 0:
        return rv-1
    return rv
 
def min_eat_time(diners):
    
    diners.sort()
    diners = diners[::-1]
    diners_to_divide = 0
    next_diner_cakes = diners[diners_to_divide]
    dlen = len(diners)
    min_time = diners[0]
    target_size = min_time-1
    
    while target_size > 0:
        
        while diners_to_divide < dlen and next_diner_cakes > target_size:
            diners_to_divide+=1
            if diners_to_divide < dlen:
                next_diner_cakes = diners[diners_to_divide]
            else:
                next_diner_cakes = 0
        
        cur_diner = 0
        moves_required = 0
        while cur_diner < diners_to_divide:
            
            moves_required += divide_stack(diners[cur_diner],target_size)
            cur_diner += 1
            
        if moves_required > min_time:
            break
            
        if target_size+moves_required < min_time:
            min_time = target_size+moves_required
        
        target_size -= 1
        
    return min_time
    
def main():
    num_test_cases = int(raw_input().strip())
    
    test_cases = []
    rnt = range(num_test_cases)
    for n in rnt:
        line = raw_input() # first line unnecessary
        test_cases.append([int(x) for x in raw_input().strip().split()])
        
    case = 0
    output = []
    while case < num_test_cases:
        co = "Case #"+str(case+1)+": "+str(min_eat_time(test_cases[case]))
        output.append(co)
        case+=1
    
    print "\n".join(output)
    
if __name__ == '__main__':
    main()