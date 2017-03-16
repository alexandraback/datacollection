

#include <stdio.h>

int number_of_cases;

int main() {
    scanf("%d",&number_of_cases);
    
    for (int case_number=1;case_number<=number_of_cases;case_number++){
        char audience[1005];
        int max_shyness;
        scanf("%d %s",&max_shyness,audience);
        int number_standing=0;
        int number_of_friends_I_need_to_bring=0;
        for (int i=0;i<=max_shyness;i++){
            if (audience[i]=='0') continue;
            if (number_standing>=i) number_standing=number_standing+(audience[i]-'0'); else {
                number_of_friends_I_need_to_bring+=(i-number_standing);
                number_standing=i+(audience[i]-'0');
            }
                
        }
        
        printf("Case #%d: %d\n",case_number,number_of_friends_I_need_to_bring);
        
    }
    
    return 0;
}
