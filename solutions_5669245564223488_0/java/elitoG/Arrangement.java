import java.util.ArrayList;
 
class Arrangement{ 
     
     
    private String[] str = null; 
     
    public Arrangement(String[] s){ 
        this.str = s; 
    } 
     
    public ArrayList<String> sort(){ 
        int num=str.length; 
        ArrayList<String> output = new ArrayList<>();
        int[] n1 = new int[num -1]; 
        int[] nss = new int[num]; 
        String[] s = new String[num]; 
         
        boolean flag = false; 
        int x = 0; 
         
        do{ 
            if(x == 0){
                for(int i = 0;i < num - 1;i ++){ 
                    n1[i] = 0; 
                } 
            } else {
                for(int i = 0;i < num - 1;i ++){ 
                    if(n1[num - 2 - i] < i + 1){ 
                        n1[num - 2 - i] ++; 
                        for(int j=num-1-i;j<num-1;j++){ 
                            n1[j] = 0; 
                        } 
                        break; 
                    } 
                } 
            } 
            for(int i = 0;i < num - 1;i++){ 
                if(n1[i] == (num - 1 - i)){ 
                    flag = false; 
                } else { 
                    flag = true; 
                    break; 
                } 
            } 
            for(int i = 0;i < num;i++){
                nss[i] = 0; 
            } 
            for(int i = 0;i < num - 1;i++){
                int hh = 0, j = 0;
                do{ 
                    if(nss[num - 1 - hh] == 1){ 
                        hh++; 
                        continue; 
                    } else { 
                        if(j == n1[i]){ 
                            break;
                        } else { 
                            hh++; 
                            j++; 
                        } 
                    } 
                } while(true); 
                hh = num - 1 - hh; 
                s[hh] = str[num-1-i]; 
                nss[hh] = 1; 
            } 
            for(int i = 0; i < num;i++){
                if(nss[i] == 0) { 
                    s[i] = str[0]; 
                    break; 
                } 
            } 
            ++x;
            String train = "";
            for(int i = 0;i < num;i++){
            	train = new StringBuffer (train).append(s[i]).toString();
            	//train += s[i];
            } 
            output.add(train);
        }while(flag); 
        return output;
    } 
} 
