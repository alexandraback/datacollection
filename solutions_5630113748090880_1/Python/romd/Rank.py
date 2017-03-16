LINES_PARAM = 0
INPUT_FILE_NAME = 'B-large.in'
OUTPUT_FILE_NAME = 'B-large.out'

def do_case(parsed):
        evenNums=set()
        for line in parsed[1:]:
                for num in line:
                        if num in evenNums:
                                evenNums.remove(num)
                        else:
                                evenNums.add(num)
        ans=sorted(list(evenNums))
        result=""
        for n in ans:
                result=result+str(n)+" "
        return str(result[:-1])
def do_parse(input):
        return [[int(num) for num in line.rstrip().split(" ")]for line in input]
def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
        temp=input_f.readlines()
        index=0
        for test_case in range(num_of_test_cases):
                lines=int(temp[index].rstrip().split(" ")[LINES_PARAM])*2-1
                parsed_input = do_parse(temp[index:index+lines+1])
                index=index+1+lines
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
