# author: yagoa0o
# date : 2015/04/11
import math
class Solution():
    def get_result(self,input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name,"w+")
        total = int(infile.readline())
        #main procedure
        for i in range(total):
            d = int(infile.readline())
            pi_input = infile.readline().split()
            current_best_time = 0
            p_array = []
            #get pi and sort
            for pi in range(d):
                self.insert(p_array, int(pi_input[pi]))
            flag = d - 1
            current_best_eat_time = p_array[len(p_array) - 1]
            current_best_oper_time = 0
            current_best_time = current_best_eat_time + current_best_oper_time

            #find pn which the number(x|px >= pn) >1/2 pn
            while flag > 0:
                if p_array[flag - 1] != p_array[flag]:
                    #judge
                    if d - flag > (p_array[flag]) / 2:
                        break
                flag -= 1
            #count
            eat_time = p_array[flag]

            if flag == 0:
                #special case like 99
                eat_time = int(math.sqrt(eat_time))
            while eat_time < current_best_time:
                while p_array[flag] < eat_time:
                    flag += 1
                new_oper_time = 0
                for j in range(flag, d):
                    if p_array[j] % eat_time == 0:
                        new_oper_time += p_array[j] / eat_time - 1
                    else:
                        new_oper_time += p_array[j] / eat_time
                if eat_time + new_oper_time < current_best_time:
                    current_best_eat_time = eat_time
                    current_best_oper_time = new_oper_time
                    current_best_time = current_best_eat_time + current_best_oper_time
                eat_time += 1
            outfile.write('Case #' + str(i + 1) + ': ' + str(current_best_time) + '\n')
        infile.close()
        outfile.close()

    def insert(self, lst, number):
        position = 0
        while position < len(lst):
            if number < lst[position]:
                lst.insert(position, number)
                return
            position += 1
        lst.append(number)
        return

solu = Solution()
file_name = 'B-small-attempt1'
solu.get_result(file_name + '.in', file_name + '.out')
