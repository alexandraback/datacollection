OUTPUT_FILE_NAME = 'Csmall.out'

def do_case(parsed_input):
        return str(results)

def pow2to100(input):
        t=bin(input)[2:]
        r=''
        for i in t:
                r=r+'0'+i
        return int(r)

def main():
        output = []
        output.append('Case #1:')
        for i in range(50):
                temp=100000000000001+100*pow2to100(i)
                temp*=11
                output.append(str(temp)+' 3 4 5 6 7 8 9 10 11')

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
        output_f.close()
	
if __name__ == '__main__':
        main()
